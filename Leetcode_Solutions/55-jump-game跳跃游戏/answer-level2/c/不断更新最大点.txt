```
bool canJump(int* nums, int numsSize)
{
    if (numsSize == 0) return 1;
    int curJump = 0;
    int maxJump = nums[curJump];
    while(curJump != numsSize - 1 && maxJump >= curJump + 1) {
        curJump++;
        if (curJump + nums[curJump] > maxJump)
            maxJump = curJump + nums[curJump];
    }
    if (curJump == numsSize - 1)
        return true;
    return false;
}
```
