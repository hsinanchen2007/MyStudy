### 解题思路
快慢指针，不同的是fast从1开始，并且需要注意循环的条件

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(nums == NULL || numsSize == 0) {
        return 0;
    }

    int slow = 0;
    int fast = 1;

    while (fast < numsSize) {
        if (nums[fast] == nums[slow]) {
            fast++;
        }else {
            nums[++slow] = nums[fast];
        }
    }

    return slow + 1;
}
```