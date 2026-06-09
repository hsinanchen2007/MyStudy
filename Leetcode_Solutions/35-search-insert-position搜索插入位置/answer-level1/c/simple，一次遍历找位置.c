### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
int i;
if(numsSize==0)
return 0;
for(i=0;i<numsSize&&nums[i]<target;i++);
return i;
}
```