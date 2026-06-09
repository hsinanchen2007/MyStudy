### 解题思路
与移除0元素是一样的，把非目标值挨个写入，最后返回慢指针的长度

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int slow = 0;
    int fast = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[fast] == val) {
            fast++;
        }else {
            nums[slow++] = nums[fast++];
        }
    }

    return slow;
}
```