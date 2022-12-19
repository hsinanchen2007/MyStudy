### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
int findUnsortedSubarray(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int max = nums[0];
    int min = nums[numsSize - 1];
    int r = 0;
    int l = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        max = MAX(max, nums[i]);
        min = MIN(min, nums[numsSize - 1 - i]);
        //从左往右扫
        if (nums[i] < max) {
            r = i;
        }
        if (nums[numsSize - 1 - i] > min) {
            l = numsSize - 1 - i;
        }
    }
    return r > l ? r - l + 1 : 0;
}
```