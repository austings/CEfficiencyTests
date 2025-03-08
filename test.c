#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 10000000  // 10 million iterations

typedef struct {
    int x1, y1, end;
} Line;

int main() {
    srand(time(NULL));

    // Generate random test data
    Line h = {rand() % 1000, rand() % 1000, rand() % 1000 + 1000};
    Line v = {rand() % 1000, rand() % 1000, rand() % 1000 + 1000};
    int horizontalYs = rand() % 1000;

    long long count1 = 0, count2 = 0;
    clock_t start, end;
    
    // Test single if-statement
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        if (h.y1 == horizontalYs && h.x1 < v.x1 && h.end > v.x1 && v.y1 < h.y1 && v.end > h.y1) {
            count1++;
        }
    }
    end = clock();
    double time1 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Single if-statement: %f seconds\n", time1);

    // Test multiple if-statements with early exits
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        if (h.y1 != horizontalYs) continue;
        if (h.x1 >= v.x1) continue;
        if (h.end <= v.x1) continue;
        if (v.y1 >= h.y1) continue;
        if (v.end <= h.y1) continue;
        count2++;
    }
    end = clock();
    double time2 = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Multiple if-statements: %f seconds\n", time2);

    printf("Counts: %lld vs %lld\n", count1, count2);

    return 0;
}
