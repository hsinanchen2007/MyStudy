遍历数组，第count个target使用1/count的概率选出

执行用时 :76 ms, 在所有 c 提交中击败了79.49%的用户
内存消耗 :12.9 MB, 在所有 c 提交中击败了100.00%的用户

typedef struct {
    int* nums;
    int numsSize;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = malloc(sizeof(Solution));
    obj->nums = nums;
    obj->numsSize = numsSize;

    return obj;
}

int solutionPick(Solution* obj, int target) {
    int i = 0, j = 0, cnt = 0, ret = -1;

    if(NULL == obj)
        return -1;

    for(i = 0; i < obj->numsSize; i++)
    {
        if(target == obj->nums[i])
        {
            if(0 == cnt++)
                ret = i;
            else
            {
                j = rand()%cnt;
                if(j < 1)
                    ret = i;
            }
        }
    }

    return ret;
}

void solutionFree(Solution* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 
 * solutionFree(obj);
*/