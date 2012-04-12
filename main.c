#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

const int T[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 3, 3, 3, 4, 4, 4, 5, 5, 5, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 6, 6, 6, 7, 7, 7, 8, 8, 8, 6, 6, 6, 7, 7, 7, 8, 8, 8};

int main() {
	int i, j, x = 0, numIterations = 10000000;
	struct timeval start, end;
	time_t elapsed_time_us;
	double elapsed_time;
	
	/*
	 * It would be real nice if gcc 4.6.3 interchanged these loops as it
	 * enables further optimization (hoist inner calculation).
	 */
	gettimeofday(&start, NULL);
	for (i = 0; i < numIterations; i++) {
		for (j = 0; j < 81; j++) {
			x += (j - 9 * (j / 9)) / 3 + 3 * (j / 27);
			/* x += T[j]; */
		}
	}
	gettimeofday(&end, NULL);
	
	elapsed_time_us = end.tv_usec - start.tv_usec;
	elapsed_time_us += 1000000l * (end.tv_sec - start.tv_sec);
	elapsed_time = (double)(elapsed_time_us / 1000000.);
	
	printf("Summation: %d\n", x);
	printf("%d iterations: %.3fs\n", numIterations, elapsed_time);

	return EXIT_SUCCESS;
}

