#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 10000000  // 10 million iterations per test
#define TESTS 10000          // 10,000 tests

typedef struct {
    int x1, y1, end;
} Line;

// High-resolution timing function
double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

int main() {
    srand(time(NULL));

    long long count1 = 0, count2 = 0;
    double totalTime1 = 0, totalTime2 = 0;

    for (int t = 0; t < TESTS; t++) {
        // Generate new random test data for each test
        Line h = {rand() % 1000, rand() % 1000, rand() % 1000 + 1000};
        Line v = {rand() % 1000, rand() % 1000, rand() % 1000 + 1000};
        int horizontalYs = rand() % 1000;

        double start, end;

        // Test single if-statement
        start = get_time();
        for (long long i = 0; i < ITERATIONS; i++) {
            if (h.y1 == horizontalYs && h.x1 < v.x1 && h.end > v.x1 && v.y1 < h.y1 && v.end > h.y1) {
                count1++;
            }
        }
        end = get_time();
        totalTime1 += end - start;

        // Test multiple if-statements with early exits
        start = get_time();
        for (long long i = 0; i < ITERATIONS; i++) {
            if (h.y1 != horizontalYs) continue;
            if (h.x1 >= v.x1) continue;
            if (h.end <= v.x1) continue;
            if (v.y1 >= h.y1) continue;
            if (v.end <= h.y1) continue;
            count2++;
        }
        end = get_time();
        totalTime2 += end - start;
    }

    printf("Average execution time (Single if-statement): %f seconds\n", totalTime1 / TESTS);
    printf("Average execution time (Multiple if-statements): %f seconds\n", totalTime2 / TESTS);
    printf("Counts: %lld vs %lld\n", count1, count2);

    return 0;
}
