#include<stdio.h>
#include<time.h>
#include<stdbool.h>

long pow2(int pwr) {
    long result = 1L;
    for(int i = 0; i < pwr; i++) {
        result *= 2L;
    }
    return result;
}

bool is_prime(long p) {
    long sum = 0L;
    for(long div = 1L; div < p; div++) {
        if(p % div == 0) {
            sum += div;
        }
    }
    return sum == 1L;
}

long perfect(int p) {
    if(is_prime(pow2(p) - 1)) {
        return pow2(p-1) * (pow2(p)-1);
    }
    return 0L;
}

int main() {
    int max_exp;
    long perfect_num;
    printf("Enter max mersenne prime to search: ");
    scanf("%d", &max_exp);
    clock_t duration = clock();
    for(int exp = 1; exp <= max_exp; exp++) {
        if(is_prime(exp)) {
            perfect_num = perfect(exp);
            if(perfect_num != 0) {
                printf("%ld is a perfect number with a mersenne prime of %d\n", perfect_num, exp);
            }
        }
    }
    duration = clock() - duration;
    duration *= 1000;
    duration /= CLOCKS_PER_SEC;
    printf("Duration: %ldms\n", duration);
    return 0;
}