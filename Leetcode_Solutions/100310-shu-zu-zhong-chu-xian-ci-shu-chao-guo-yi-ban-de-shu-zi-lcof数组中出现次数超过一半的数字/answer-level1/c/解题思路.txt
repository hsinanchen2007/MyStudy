### 解题思路
投票算法，实现很简单

### 代码

```c
int majorityElement(int* nums, int numsSize) {
    int i;
    int num;
    int count;

    count = 0;
    for (i = 0; i<numsSize; i++) {
        if (count == 0) {
            num = nums[i];
            count++;
        }
        else {
            if (num == nums[i]) {
                count++;
            }
            else {
                count--;
            }
        }
    }

    return num;
}
```