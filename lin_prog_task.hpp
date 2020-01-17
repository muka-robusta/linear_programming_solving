#ifndef LIN_PROG_TASK
#define LIN_PROG_TASK

#include "entity.hpp"

struct LinProgTask {
	Entity ** canonic_matrix_a;
	int vec_num;
	int restrict_num;
	int art_vec_quantity;

	int * basis_vec_numbers;
	int * artificial_vec_numbers;

	Entity * c_i;
	double * a_0;
};

#endif