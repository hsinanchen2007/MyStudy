### 解题思路
此处撰写解题思路

### 代码

```c
void moveZeroes(int* nums, int numsSize){
    int *res = calloc(numsSize, sizeof(int));
    int i = 0;
    int j = 0;

    for (i = 0; i < numsSize; i++) {
        if(nums[i]) {
            res[j++] = nums[i];
        }
    }

    while(j < numsSize) {
        res[j++] = 0;
    }

    memcpy(nums, res, sizeof(int) * numsSize);
}
```