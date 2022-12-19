### 解题思路
看了很多的贪心题解，感觉都少考虑了一些问题，就是在比较maxJump的时候没有考虑到可能根本跳不到下一跳

### 代码

```c
bool canJump(int* nums, int numsSize){
    int maxJump = -1;
    if(numsSize == 1)   return true;
    for(int numIndex = 0; numIndex < numsSize-1; numIndex++){
        // 保证可达下一个
        if(maxJump == 0)    return false;
        maxJump = (maxJump>=(nums[numIndex]+numIndex))?maxJump:(nums[numIndex]+numIndex);
        // 中间可能到0
        if(maxJump - numIndex == 0) return false;
        if(maxJump >= numsSize-1) return true;
    }
    return false;
}
```