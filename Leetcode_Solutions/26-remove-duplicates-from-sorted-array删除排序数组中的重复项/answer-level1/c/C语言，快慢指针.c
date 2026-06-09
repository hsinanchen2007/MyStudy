### 解题思路
快慢指针，每次遇到相等的，fast往前推；
不相等的，把当前值给++slow，fast和slow都往前推一个。
直到结束后，slow所指向的下标就是数组的完结长度，由于slow从0开始计数，所以长度是slow+1

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int fast = 1;
    int slow = 0;
    while (fast < numsSize) {
        if (nums[slow] != nums[fast]) {
            nums[++slow] = nums[fast++];
        }else {
            fast++;
        }
    }
    return (slow + 1);
}
```