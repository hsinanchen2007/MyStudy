### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}
int removeElement(int* nums, int numsSize, int val){
     qsort(nums, numsSize, sizeof(int), cmp);

     int cnt, index, i;
     cnt = index = 0;
     for (i = 0; i < numsSize; i++) {
         if (nums[i] == val) {
             index = i;
             cnt++;
         }
     }

     for (i = index - cnt + 1; i + cnt < numsSize; i++) {
         nums[i] = nums[i + cnt];
     }

     return numsSize - cnt;
}
```