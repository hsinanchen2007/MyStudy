
#define SPACE_LEN 1024
int g_permuteCnt = 0;
int *g_cache = NULL;
bool *g_used = NULL;

void step(int *nums, int numsSize, int sortedCnt, int **result, int **returnColumnSizes)
{
    if (sortedCnt == numsSize) {
        result[g_permuteCnt] = (int *)malloc(sizeof(int) * numsSize);
        if (result[g_permuteCnt] == NULL) {
            return;
        }
        memcpy(result[g_permuteCnt], g_cache, sizeof(int) * numsSize);
        (*returnColumnSizes)[g_permuteCnt] = numsSize;
        g_permuteCnt++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (g_used[i]) {
            continue;
        }
        g_used[i] = true;
        g_cache[i] = nums[sortedCnt];
        step(nums, numsSize, sortedCnt + 1, result, returnColumnSizes);
        g_used[i] = false;
    }
}

int** permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    if (nums == NULL || numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    int **result = (int **)malloc(sizeof(int *) * SPACE_LEN);
    *returnColumnSizes = (int *)malloc(sizeof(int) * SPACE_LEN);
    g_cache = (int *)malloc(sizeof(int) * numsSize);
    g_used = (bool *)malloc(sizeof(bool) * numsSize);
    if (result == NULL || *returnColumnSizes == NULL || g_cache == NULL || g_used == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(result, NULL, sizeof(int *) * SPACE_LEN);
    memset(*returnColumnSizes, 0, sizeof(int) * SPACE_LEN);
    memset(g_cache, 0, sizeof(int) * numsSize);
    memset(g_used, false, sizeof(bool) * numsSize);

    g_permuteCnt = 0;
    int sortedCnt = 0;
    step(nums, numsSize, sortedCnt, result, returnColumnSizes);

    free(g_cache);
    free(g_used);
    *returnSize = g_permuteCnt;
    return result;
}