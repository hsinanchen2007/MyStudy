### 解题思路

层层递归，找到每层能到达最远的那个位置，再递归直到到不了终点或者能到达终点时结束

找到每层能到达最远的那个位置的逻辑：
1、当前层可以跳到的最远步数小于当前位置能跳到的下一个位置处的步数
2、当前层可以跳到的最远步数小于当前位置减去上一个最远位置（这个条件容易遗漏）

递归结束条件：
1、找不到，返回false
2、能找到，并且可以跳到或者跳过终点，返回true

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 0) {
            // 空数组返回false
            return false;
        }
        if (n == 1) {
            // 一个值开始即终点，不需要跳也能到，返回true
            return true;
        }
        if ((nums[0] + 1) >= n) {
            // 开始就能跳到终点，返回true
            return true;
        }
        // 层层递归，找到每层能到达最远的那个位置，再递归直到到不了终点或者能到达终点时结束
        return helper(nums, 0, n);
    }
    bool helper(vector<int>& nums, int pos, int n) {
        // printf("maxPos:%d, pos:%d\n", maxPos, pos);        
        int maxSteps = INT_MIN;
        int maxPos = pos;
        for (int i = pos+1; i <= (pos+nums[pos]) && i < n; i++) {
            // printf("i:%d, nums[i]:%d, nums[pos]:%d\n", i, nums[i], nums[pos]);
            if (maxSteps <= nums[i] || maxSteps <= (i - maxPos)) {
                // 每层能到到最远的那个位置的条件有二个：
                // 1、当前层可以跳到的最远步数小于当前位置能跳到的下一个位置i处的步数
                // 2、当前层可以跳到的最远步数小于当前位置减去上一个最远位置（这个条件容易遗漏）
                maxSteps = nums[i];
                maxPos = i;
            }
        }
        if (maxSteps == INT_MIN) {
            // 找不到那个最远的距离了，意味着到不了终点
            return false;
        }
        // printf("maxPos=%d\n", maxPos);
        if ((maxPos + nums[maxPos] + 1) >= n) {
            // 从当前层最远位置跳最远，能到达终点，则返回true
            return true;
        } else {
            // 从当前层最远位置跳最远，能到达终点，否则继续寻找
            return helper(nums, maxPos, n);
        }
    }
};
```