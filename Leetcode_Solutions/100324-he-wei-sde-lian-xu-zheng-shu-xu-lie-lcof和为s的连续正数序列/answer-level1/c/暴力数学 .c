```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    long long i, j;
    long long sum1, sum2;
    int **res = malloc(sizeof(int *) * target);
    int *col = malloc(sizeof(int) * target);
    int count = 0;

    for (i = 0; i <= target; i++) {
        sum1 = i * (i + 1) / 2;
        for (j = i + 2; j <= target; j++) {
            sum2 = j * (j + 1) / 2;
            if (sum2 - sum1 == target) {
                res[count] = malloc(sizeof(int) *  (j - i));
                col[count] = j - i;
                int index = 0;
                for (int k = i + 1; k <= j; k++) {
                    res[count][index++] = k;
                }
                count++;
                break;
            }

            if (sum2 - sum1 > target) {
                break;
            }
        }
    }

    *returnSize = count;
    *returnColumnSizes = col;
    return res;
}

```
