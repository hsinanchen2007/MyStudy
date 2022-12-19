### 解题思路
此处撰写解题思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i = 1;
    int j = 0;

    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    while (i < numsSize) {
        if (nums[i] == nums[j]) {
            i++;
        } else {
            nums[++j] = nums[i++];
        }
    }

    return (j + 1);
}
```