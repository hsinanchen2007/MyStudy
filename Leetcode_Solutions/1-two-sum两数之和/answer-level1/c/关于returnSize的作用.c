### 解题思路
不是很理解这个传入的returnSize的作用
暂且猜测出题人的意图是，如果对目标值target可以找到答案，则returnSize为2，否则为0

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   static int returnArray[2]={0};
   *returnSize = 2;
   for(int i=0;i<numsSize-1;i++)
   {
       for(int j=i+1;j<numsSize;j++)
       {
           if(nums[i]+nums[j]==target)
           {
               returnArray[0]=i;
               returnArray[1]=j;
            }
        }
    }
    return returnArray;
}
```