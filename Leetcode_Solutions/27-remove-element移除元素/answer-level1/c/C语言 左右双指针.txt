### 解题思路
去掉getValCnt，在proc获取cnt可以更快，不过分开看着清楚些

![image.png](https://pic.leetcode-cn.com/affaf8fbec2fe4c591f7c28d9f18faa940d99d6d837c8c7953e032a928d946bc-image.png)

### 代码

```c
int getValCnt(int* nums, int numsSize, int val)
{
    int i;
    int cnt = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            cnt++;
        }
    }
    return cnt;
}
void proc(int* nums, int numsSize, int val)
{
    int l, r;
    int tmp;
    l = 0;
    r = numsSize - 1;
    while (l < r) {
        if (nums[l] != val) {
            l++;
            continue;
        }
        if (nums[r] == val) {
            r--;
            continue;
        }
        tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }
}
int removeElement(int* nums, int numsSize, int val){
    int rlt;
    int cnt;
    cnt = getValCnt(nums, numsSize, val);
    if (cnt == 0) {
        return numsSize;
    }
    proc(nums, numsSize, val);
    return numsSize - cnt;
}
```