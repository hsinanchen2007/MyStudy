### 解题思路
此处撰写解题思路
先排序，再遍历数出数组中有多少个不同的数字
### 代码

```c
int compare(const void* a, const void*b){
    if( *(int*)a>*(int*)b) return 1;
    if( *(int*)a<*(int*)b) return -1;
    else return 0;
}
int thirdMax(int* nums, int numsSize){
   if(numsSize<3) return nums[0]>nums[1] ? nums[0] : nums[1];
   qsort(nums, numsSize, sizeof(int), compare);
   int i, cnt=1, flag=0;
   for(i=numsSize-1;i>0;i--){
       if(nums[i]!=nums[i-1]) cnt++;
       if(cnt==3){
           flag=1;
           break;
       }
   }
    if(flag==1) return nums[i-1];
    return nums[numsSize-1];
}
```