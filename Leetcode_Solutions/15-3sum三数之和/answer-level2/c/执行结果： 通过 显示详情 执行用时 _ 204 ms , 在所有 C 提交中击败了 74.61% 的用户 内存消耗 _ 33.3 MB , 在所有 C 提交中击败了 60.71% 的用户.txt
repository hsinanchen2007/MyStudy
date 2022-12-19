

int compare(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize =0;
    int **result = (int**)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);

    qsort(nums, numsSize, sizeof(int), compare);

    //查询
    int i,pos_column=0;
    int pos1,pos2;
    
    for (i = 0; i < numsSize-2; i++)
    {
        if (i == 0 || (i > 0) && (nums[i] != nums[i-1]))
        {
            pos1 = (i+1);
            pos2 = (numsSize-1);
            while (pos1 < pos2)
            {
                if (nums[i] + nums[pos1] + nums[pos2] == 0)
                {
                    result[*returnSize] = (int*)malloc(sizeof(int)*3);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[pos1];
                    result[*returnSize][2] = nums[pos2];
                    (*returnColumnSizes)[pos_column] = 3;
                    pos_column++;
                    (*returnSize)++;
                    while (pos1 < pos2 && nums[pos1] == nums[pos1+1]) pos1++;
                    while (pos1 < pos2 && nums[pos2] == nums[pos2-1]) pos2--;
                    pos1++;
                    pos2--;
                }
                else if (nums[i] + nums[pos1] + nums[pos2] > 0)
                {
                    pos2--;
                }
                else if (nums[i] + nums[pos1] + nums[pos2] < 0)
                {
                    pos1++;
                }
            }
        }
    }
    return result;
}