### 解题思路
此处撰写解题思路

### 代码

```c
bool is_ou(int nums)
{
    int i = 0;
    while (nums) {
        nums /= 10;
        i++;
    }
    if (i % 2 == 0) {
        return true;
    }

    return false;
}

int findNumbers(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return -1;
    }

    int i;
    int result = 0;
    for (i = 0; i < numsSize; i++) {
        if (is_ou(nums[i])) {
            result++;
        }
    }

    return result;
}
```