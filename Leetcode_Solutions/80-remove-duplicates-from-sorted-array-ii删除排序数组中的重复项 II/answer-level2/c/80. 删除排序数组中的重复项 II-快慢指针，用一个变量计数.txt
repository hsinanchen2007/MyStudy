### 解题思路
快慢指针，要增加一个变量来计数

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    
    int slow = 0;
    int fast = 1;
    int cnt = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[fast] == nums[slow] && cnt < 2) {
            nums[++slow] = nums[fast++];
            cnt++;
        }else if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast++];
            cnt = 1;
        }else {
            fast++;
        }
    }
    
    return (slow + 1);
}
```