

void dfs(int *nums,int numsSize,int* returnSize,int *deep,int *flg, int **res, int* cur)
{
    int *tmp = NULL;


    for(int i = 0; i < numsSize; i++)
    {
        if(flg[i] != 1)
        {
            cur[*deep] = nums[i];
            (*deep)++;
            if((*deep) == numsSize)
            {
                res[(*returnSize)] = malloc(numsSize * sizeof(int));
                memcpy(res[(*returnSize)], cur, numsSize * sizeof(int));
                (*returnSize)++;
                (*deep)--;
                return;
            }
            else
            {
                flg[i] = 1;
                dfs(nums,numsSize,returnSize,deep,flg, res, cur);
                flg[i] = 0;
                (*deep)--;
            }
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int **res = NULL;
    int *flag = NULL;
    int *current = NULL;
    int deep = 0;
    *returnSize = 0;


    res = malloc(888*sizeof(int*));
    if(res == NULL)
    {
        return NULL;
    }

    flag = malloc(numsSize * sizeof(int));
    if(flag == NULL)
    {
        return NULL;
    }
    memset(flag, 0, numsSize * sizeof(int));

    current = malloc(numsSize * sizeof(int));

    dfs(nums,numsSize,returnSize,&deep,flag, res, current);

    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }

    return res;

}