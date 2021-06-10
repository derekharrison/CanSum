/*
 * main.cpp
 *
 *  Created on: Jun 10, 2021
 *      Author: d-w-h
 */

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef struct table_element {
    bool is_set = false;
    bool sum_possible;
} t_elem;

int num_calls = 0;

bool can_sum(int n, int A[], int target_sum, int sum, t_elem** m_table) {

    bool sum_possible = false;

    num_calls++;

    if(m_table[sum]->is_set == true) {
        return m_table[sum]->sum_possible;
    }
    else {
        for(int i = 0; i < n; ++i) {
            int sum_o = sum + A[i];
            if(sum_o != sum) {
                if(target_sum == sum_o) {
                    return sum_possible = true;
                }
                else if(sum_o < target_sum) {
                    sum_possible = can_sum(n, A, target_sum, sum_o, m_table);
                    if(sum_possible == true) {
                        return sum_possible = true;
                    }
                }
            }

        }

        m_table[sum]->is_set = true;
        m_table[sum]->sum_possible = sum_possible;
    }

    return sum_possible;
}

bool is_sum_possible(int n, int A[], int target_sum) {

    t_elem** m_table = new t_elem*[target_sum+1];

    for(int i = 0; i < target_sum + 1; ++i) {
        m_table[i] = new t_elem;
        m_table[i]->is_set = false;
        m_table[i]->sum_possible = false;
    }

    return can_sum(n, A, target_sum, 0, m_table);
}

int main(int argc, char* argv[]) {

    int N = 2;
//    int* A = new int[N];

    int A[] = {7, 14};
//    A[0] = 1;
//    A[1] = 1;

    //Seed random number generator
//    srand (time(NULL));

    //Initialize cost array with random numbers
    for(int i = 0; i < N; ++i) {
//        A[i] = rand() % 4 + (5*i)/2;
    }

    for(int i = 0; i < N; ++i) {
        printf("A[%i]: %i\n", i, A[i]);
    }

    int target_sum = 300;

    bool sum_possible = is_sum_possible(N, A, target_sum);

    printf("n: %i\nsum_possible: %i\n", N, sum_possible);

    printf("num_calls: %i\n", num_calls);

    printf("done\n");

    return 0;
}
