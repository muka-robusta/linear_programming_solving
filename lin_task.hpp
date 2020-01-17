#ifndef LIN_PROG
#define LIN_PROG

#include "entity.hpp"
#include "lin_prog_task.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


/*
	
	sign:

	=  - 0
	<= - 1
	>= - 2

*/

void solve_simpleks(Entity ** matrix_a, Entity * vec_c, double * vec_a0, int * vec_sign) 
{

}

void print_matrix(Entity ** matrix,int size_i, int size_j, int artif_num)
{
    for(int i = 0; i < size_i; i++)
    {
        for(int j = 0; j < size_j; j++)
        {
        	cout << "[" ;
        	//cout << setw(5) << matrix[i][j].get_coef(0);
            for(int m = 0; m < artif_num; m++)
            {
            	cout << setw(5) << matrix[i][j].get_coef(m) << " ";
            	//cout << " " << matrix[i][j] << " + ";
            }
            cout << "]";
        }
        cout << endl;
    }
}

void print_vector(Entity * vector,int size, int artif_num)
{
    cout << "( ";
    for(int i = 0; i < size; i++)
    {
        cout << "[";
        for(int m = 0; m < artif_num; m++)
        {
        	cout << vector[i].get_coef(m) << " ";
        }
        cout << "], ";
    }    
    cout << " )" << endl;
}


LinProgTask * to_canonic(double ** matrix_a, int * vec_sign, double * vec_a0, int var_num, int restrict_num)
{
	int a_dim_j = var_num;
	int a_dim_i = restrict_num;
	int artificial_number_var = 0;
	
	for(int i = 0; i < a_dim_i; i++)
	{
		if(vec_sign[i] == 1){
			a_dim_j++;
		}else if(vec_sign[i] == 2)
		{
			a_dim_j = a_dim_j + 2;
			artificial_number_var++;
		}
	}

	Entity ** new_matrix_a = new Entity*[a_dim_i];
	int * basis_vec_numbers = new int[restrict_num];
	int * artificial_vec_numbers = new int[artificial_number_var];

	int artificial_pos = 1;
	int artificial_vec_count = 0;

	for(int i = 0; i < a_dim_i; i++)
	{
		new_matrix_a[i] = new Entity[a_dim_j];
		for(int j = 0; j < a_dim_j; j++)
		{
			new_matrix_a[i][j].allocate_coef(artificial_number_var + 1);
			if(j < var_num)
			{
				new_matrix_a[i][j].set_coef(0, matrix_a[i][j]);	
				cout << matrix_a[i][j] << endl;
			}else {
				new_matrix_a[i][j].set_coef(0, 0);
			}
		}

		if(vec_sign[i] == 1)
		{
			new_matrix_a[i][var_num + artificial_pos - 1].set_coef(0, 1);
			basis_vec_numbers[i] = var_num + artificial_pos - 1;

			artificial_pos++;
		}else if(vec_sign[i] == 2)
		{
			new_matrix_a[i][var_num + artificial_pos - 1].set_coef(0, -1);
			artificial_pos++;

			new_matrix_a[i][var_num + artificial_pos - 1].set_coef(0, 1);
			basis_vec_numbers[i] = var_num + artificial_pos - 1;
			artificial_vec_numbers[artificial_vec_count] = var_num + artificial_pos - 1;

			artificial_pos++;
			artificial_vec_count++;
		}

	}

	LinProgTask * task = new LinProgTask;
	task -> restrict_num = restrict_num;
	task -> vec_num = a_dim_j;
	task -> art_vec_quantity = artificial_vec_count;

	task -> canonic_matrix_a = new_matrix_a;
	task -> basis_vec_numbers = basis_vec_numbers;
	task -> artificial_vec_numbers = artificial_vec_numbers;


	//print_matrix(new_matrix_a, a_dim_i, a_dim_j, artificial_number_var);
	return task;

}

Entity * get_delta(LinProgTask * task)
{
	Entity * delta_vec = new Entity[task -> vec_num];
	
	for(j = 0; j < task -> vec_num; j++)
	{
		delta_vec[j].allocate_coef(task -> art_vec_quantity);	
	}

	for(int i = 0; i < task -> restrict_num; i++)
	{
		for(j = 0; j < task -> vec_num; j++)
		{
			delta_vec[j] = (task -> c_i[i]) * (task -> canonic_matrix_a)[i][j];
		}
	}

	for(j = 0; j < task -> vec_num; j++)
	{
	
	}

	print_vector(delta_vec, task -> vec_num, task -> art_vec_quantity);
	return delta_vec;
}

#endif