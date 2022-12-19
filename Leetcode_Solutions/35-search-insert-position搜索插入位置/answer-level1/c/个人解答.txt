### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
  int m=0;
  if(target<nums[0]) return 0;
  if(target>nums[numsSize-1]) return numsSize;
 while(m<numsSize){
      if(nums[m]==target)
      return m;
      if((nums[m]<target)&&(nums[m+1]>target))
      return m+1;
      m++;
  }
  return m;
}
```