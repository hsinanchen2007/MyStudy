### 解题思路
如果数组都是非0的数，肯定能通过，
如果有0，则反推是否有能跳过0的值。

### 代码

```c
bool canJump(int* nums, int numsSize){
    int pre;
    int cur;
    bool pass;
    if (numsSize == 1){
        return true;
    }

    for (cur = 0; cur < numsSize - 1; cur++) {  
        if(nums[cur] == 0) {
            pass = false;
            pre = cur;
            while (pre > 0) {
                pre--;
                if (nums[pre] > (cur - pre)) {
                    pass = true;
                    break;
                }
            }
            if (!pass) {
                return pass;
            }
        } else {
            pass = true;
        }
    }
    return pass;
}
```