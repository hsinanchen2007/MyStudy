### 解题思路
//双重循环遍历寻找之和等于target，一旦找到就返回，因为该数组只有一组符合要求
### 代码

```c
  /**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0,j = 0;
    int* r= malloc(sizeof(int)*2);//申请堆空间
    memset(r,0,sizeof(int)*2);//初始化
    *returnSize = 2;//在主函数输出打印的个数len
    for(i=0;i<numsSize-1;i++){

        for(j=i+1;j<=numsSize-1;j++){
        
            if(nums[i]+nums[j]==target){
                r[0]=i;
                r[1]=j;
                return r;
            }
        
        }
    }
    return 0;
}

