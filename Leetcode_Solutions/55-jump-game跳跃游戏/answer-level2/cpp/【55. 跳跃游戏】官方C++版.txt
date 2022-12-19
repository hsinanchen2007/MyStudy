## 思路一：暴力递归（超时）
在每个位置上，判断所有可能到达的情况。
### 代码
时间复杂度：O(2^n)
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }
    bool canJump(vector<int>& nums, int pos) {
        int size = nums.size();
        if (pos == size - 1) {
            return true;
        }
        int furJump = min(pos + nums[pos], size - 1);
        for (int i = pos + 1; i <= furJump; ++i) {
            if (canJump(nums, i)) {
                return true;
            }
        }
        return false;
    }
};
```

## 思路二：记忆化搜索（超时）
自顶向下。
### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return canJump(nums, 0, memo);
    }
    bool canJump(vector<int>& nums, int pos, vector<int>& memo) {
        if (memo[pos] != -1) return memo[pos];
        int size = nums.size();
        if (pos == size - 1) {
            return memo[pos] = 1;
        }
        int furJump = min(pos + nums[pos], size - 1);
        for (int i = pos + 1; i <= furJump; ++i) {
            if (canJump(nums, i, memo)) {
                return memo[pos] = 1;
            }
        }
        return memo[pos] = 0;
    }
};
```

## 思路三：动态规划
自底向上。从右边开始动态规划，每次查询右边节点信息，不需要额外的递归开销。
### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> memo(size, -1);
        memo[size - 1] = 1;
        for (int i = size - 2; i >= 0; --i) {
            int furJump = min(i + nums[i], size - 1);
            for (int j = i + 1; j <= furJump; ++j) {
                if (memo[j] == 1) {
                    memo[i] = 1;
                    break;
                }
            }
        }
        return memo[0] == 1;
    }
};
```

## 思路四：贪心
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int index = size - 1;
        for (int i = size - 2; i >= 0; --i) {
            if (i + nums[i] >= index) {
                index = i;
            }
        }
        return index == 0;
    }
};
```




