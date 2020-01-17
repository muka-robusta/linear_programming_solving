#include <iostream>
#include <cstdlib>

#include "lin_task.hpp"
#include "lin_prog_task.hpp"

using namespace std;

int main()
{
	int var_num = 0;
	int restrict_num = 0;

	cin >> var_num;
	cin >> restrict_num;

	double ** matrix = new double*[restrict_num];
	for(int i = 0; i < restrict_num; i++)
	{
		matrix[i] = new double[var_num];
		for(int j = 0; j < var_num; j++)
		{
			double temp;
			cin >> temp;
			matrix[i][j] = temp;
		}
	}

	cout << "\nsigns\n";
	int * signs_vec = new int[restrict_num];

	for(int i = 0; i < restrict_num; i++)
	{
		int temp;
		cin >> temp;
		signs_vec[i] = temp;
	}

	cout << "\nfree el\n";
	double * vec_a0 = new double[restrict_num];

	for(int i = 0; i < restrict_num; i++)
	{
		double temp;
		cin >> temp;
		vec_a0[i] = temp;
	}

	LinProgTask * task = to_canonic(matrix, signs_vec, vec_a0, var_num, restrict_num);

	return 0;
}