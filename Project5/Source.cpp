#include <random>
#include <iostream>

void find_diff_element_column(int* ptr_List, const size_t M, const size_t N) {
	for (size_t m = 0; m < M - 1; m++) {
		bool flag = 0;
		size_t count = 0;
		
		while (count < N - 1) {
			int* tmp_ptr = ptr_List++;
			for (size_t n = count; n < N; n++) {
				if (*tmp_ptr == *ptr_List) {
					flag = 1;
					ptr_List = ptr_List + N - count;
					break;
				}
			}
			
			count++;
			ptr_List++;
			
		}
		if (flag == 1) {
			std::cout << "Non-repeating column: " << m << std::endl;
		}
	}
}

int main() {
	const size_t M = 10;
	const size_t N = 10;
	int List[M][N];
	int* ptr_List = &List[0][0];
	for (size_t index = 0; index < M * N; index++) {
		int rand_element = 1;
		*ptr_List = rand_element;
		ptr_List++;
	}
	ptr_List = &List[0][0];


	find_diff_element_column(ptr_List, M, N);
}