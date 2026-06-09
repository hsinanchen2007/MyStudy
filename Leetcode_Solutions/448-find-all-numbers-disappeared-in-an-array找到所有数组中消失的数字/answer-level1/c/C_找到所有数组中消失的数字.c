### 解题思路
因为有n个元素，每个元素的范围是1~n,所以可以有如下思路：
nums[i]的值为负数代表存在i+1这个数。或者换过来说，在1~n中存在数k,我们就把nums[k-1]标记为负数。
数组中元素的负正代表是否存在，元素的绝对值代表存在的数

第一次遍历标记
第二次遍历筛选出正值对应的坐标
第三次里边生成结果
### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int abs(int Num)
 {
     return Num>0?Num:Num*(-1);
 }
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for(int i=0;i<numsSize;++i)
        nums[abs(nums[i])-1]=abs(nums[abs(nums[i])-1])*(-1);

    int length=0;
    for(int i=0;i<numsSize;++i)
        if(nums[i]>0)
            ++length;

    int* result=(int*)malloc(sizeof(int)*length);
    for(int i=0,j=0;i<numsSize;++i)
        if(nums[i]>0)
            result[j++]=i+1;
    *returnSize=length;
    return result;
}


```