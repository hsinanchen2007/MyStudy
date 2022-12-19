### 解题思路
遍历数组中所有两个不同数的组合，当找到满足两数之和为target时，跳出循环

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *answer = (int*)malloc(sizeof(int)*2);
    bool FindoutFlag = false; // False: Not Find the Answer. True: Find Out the Answer.
    
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                answer[0] = i;
                answer[1] = j;
                FindoutFlag = true;
                break;
            }
        }

        if(FindoutFlag == true)
        {
            break;
        }
    }
    *returnSize = 2;
    return answer;
}
```