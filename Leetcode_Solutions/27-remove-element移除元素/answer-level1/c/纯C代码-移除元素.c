### 解题思路
此处撰写解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int j = 0;

    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    while (i < numsSize) {
        if (nums[i] != val) {
            nums[j++] = nums[i];
        }
        i++;
    }

    return j;
}
```