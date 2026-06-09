
符合某特定条件的`子串、子数组`问题，通常都使用`滑动窗口`解决

思路：
1. 设置一个窗口，左右指针分别指向窗口两端。初始状态时，窗口大小为0，双指针均指向数组起点
2. 让右指针向右移动，直到符合条件（左边界不变，扩大窗口）
3. 当符合条件，先记录此时的返回值，然后让左指针向右移动，直到不符合条件（右边界不变，缩小窗口）
4. 重复 2 ~ 3 步，直到左右指针均到达数组结尾

```C
#define min(a,b) ((a)<(b)?(a):(b))
int minSubArrayLen(int s, int* nums, int numsSize){
    int L = 0, R = 0, sum = 0, res = 0x7fffffff;
    while (R < numsSize) {
        while (sum < s && R < numsSize) // 扩大窗口直到符合条件
            sum += nums[R++];
        while (sum >=s && L <= R) {     // 若符合条件先记录返回值，然后缩小窗口直到不符合条件
            res = min(res, R - L);
            sum -= nums[L++];
        }
    }   
    return res == 0x7fffffff ? 0 : res; // 若 res 仍为 “无穷大”，表示未找到
}
```