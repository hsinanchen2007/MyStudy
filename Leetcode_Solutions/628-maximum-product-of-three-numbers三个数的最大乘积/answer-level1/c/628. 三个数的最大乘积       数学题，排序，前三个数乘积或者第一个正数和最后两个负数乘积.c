### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
int cmp(void* a, void* b){
    return *(int *)b - *(int *)a;
}

int maximumProduct(int* nums, int numsSize){
    int i;

    qsort(nums, numsSize, sizeof(int), cmp);
    return MAX(nums[0]*nums[1]*nums[2], nums[0]*nums[numsSize-2]*nums[numsSize-1]);
}
```