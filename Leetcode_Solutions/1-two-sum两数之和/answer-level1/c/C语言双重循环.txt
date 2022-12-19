int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   
    int * res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;    

    //令a + b = target,且a和b含于有序数集nums这个，并返回满足条件的序号
    //双重循环遍历
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i != j && (nums[i] + nums[j] == target) )
            {
                res[0] = i;
                res[1] = j;
            }
        }
    }

    return res;
}