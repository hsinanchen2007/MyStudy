```
#define MAX_SIZE 15
#define MAX_RET_SIZE 100000

int g_result[MAX_SIZE];
int g_index;
int **g_ret = NULL;
int *g_retCol = NULL;

void dfs(int* nums, int numsSize, int index, int step, int k)
{
    int i, j, flag;
    if(step == k) {
        g_ret[g_index] = (int*)malloc(sizeof(int) * k);
        for(i = 0; i < k; i++) {
            g_ret[g_index][i] = g_result[i];
        }
        g_retCol[g_index] = k;
        g_index++;
        return;
    }    
    for(i = index; i < numsSize; i++) {
        if(step == 0 || (step > 0 && nums[i] >= g_result[step - 1])) {
            flag = 0;
            for(j = index; j < i; j++) {
                if(nums[j] == nums[i]) {
                    flag = 1;
                }
            }
            if(flag) {
                continue;
            }
            g_result[step] = nums[i];
            dfs(nums, numsSize, i + 1, step + 1, k);
            while ((i + 1 < numsSize) && (nums[i] == nums[i + 1])) {
                i++;
            }
        }
    }
}

int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize < 2) {
        *returnSize = 0;
        return NULL;
    }
    g_index = 0;
    g_ret = (int**)malloc(sizeof(int*) * MAX_RET_SIZE);
    g_retCol = (int*)malloc(sizeof(int) * MAX_RET_SIZE);

    for(int i = 2; i <= numsSize; i++) {
        dfs(nums, numsSize, 0, 0, i);
    }
    *returnSize = g_index;
    *returnColumnSizes = g_retCol;   
    return g_ret;
}
```
