/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXN 1000
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int **ans = (int**)malloc(sizeof(int*) * MAXN);
    int *rcs = (int*)malloc(sizeof(int) * target);
    int L = 1;
    int sum = 0;
    int cur = 0;
    for (int i = 1; i < target; i++) {
        sum += i;
        while (sum > target) {
            sum -= L;
            L++;
        }
        if (sum == target) {
            rcs[cur] = (i - L + 1);
            ans[cur] = (int*)malloc(sizeof(int) * (i - L + 1));
            for (int k = 0; k < rcs[cur]; k++) {
                ans[cur][k] = L + k;
            }
            cur++;
        }
    }
    *returnColumnSizes = rcs;
    *returnSize = cur;
    return ans;
}