### 解题思路
此方法适用于不管后方元素。快慢指针，快指针遍历相邻元素（有序数组），慢指针保留位置。将快指针的值赋给慢指针

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
   if(numsSize==0)
   {
       return 0;
   }
   int cnt=1;
   for(int i=0;i<numsSize-1;i++)
   {
       if(nums[i+1]!=nums[i])
       {
           nums[cnt++]=nums[i+1];
       }
   }
   return cnt;
}
```