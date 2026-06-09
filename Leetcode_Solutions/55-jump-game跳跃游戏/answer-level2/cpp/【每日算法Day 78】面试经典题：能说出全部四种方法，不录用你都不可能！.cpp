> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/26ed57fd504b97c34717f7fa9a9e5201340aa84090aa54a055ea20e2f14c925a-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## 题解
### 动态规划+正推
用 $dp[i]$ 表示位置 $i$ 是否可达，初始的时候都是 $0$ ，只有 $dp[0] = 1$ ，因为起点一定是可达的。

然后从位置 $0$ 开始遍历。对于位置 $i$ ，如果发现 $dp[i] = 0$，那么从前面的位置无法到达它，那么就更无法到达后面的位置了，所以直接返回 `false` 。

否则的话，它能到达的范围是 $i+1$ 到 $i+nums[i]$ ，所以把这部分的 $dp$ 值都标记为 $1$ 。

如果发现 $i+nums[i] \ge n-1$ ，就说明当前位置直接就能跳到终点了，直接返回 `true` 。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$ 。

### 动态规划+倒推
用 $dp[i]$ 表示从位置 $i$ 能否到达终点，初始的时候都是 $0$ ，只有 $dp[n-1] = 1$ ，因为从终点一定是可到达终点的。

然后从位置 $n-2$ 开始往前遍历。对于位置 $i$ ，如果 $i+nums[i] \ge n-1$，那就说明当前位置直接就可以到达终点，那么就令 $dp[i] = 1$ 。

否则的话遍历所有的 $dp[i+1]$ 到 $dp[i+nums[i]]$ ，如果其中有等于 $1$ 的，那就说明先跳到那个位置，就能再跳到终点了。一个都没有的话 $dp[i] = 0$ 。

最后看 $dp[0]$ 是否为 $1$ 就行了。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$ 。

### 贪心+正推
在上面的动态规划方法中，对于位置 $i$ ，我们需要把他能到达的位置全部做上标记。

但是其实没有必要这么做，只需要记录一下能到的最远的那个位置 $maxx$ 就行了。如果遍历之后的位置 $j$ 时，发现 $maxx < j$ ，那就说明之前的所有位置最远都无法到达 $j$ ，那就直接返回 `false` 。否则的话，比较一下当前能到达的最远位置，更新一下 $maxx$ 的值。

时间复杂度 $O(n)$，空间复杂度 $O(1)$ 。

### 贪心+倒推
还是从上面的动态规划方法改变来的，上面动态规划在位置 $i$ ，需要遍历所有它能到达的位置，然后看有没有位置能够到达终点。

其实只需要看能到的最远的那个位置就行了，我们用 $minn$ 表示后面的位置中最靠前的那个能够到达终点的位置。如果最远到达位置满足 $i+nums[i] \ge minn$，那就说明位置 $i$ 可以直接跳到 $minn$ ，那么就更新 $minn = i$ 。否则的话怎么跳都跳不到终点，因为 $i$ 和 $minn$ 之间的位置都是无法到达终点的。

需要注意的是，这里最远的位置 $i+nums[i]$ 不一定能到达终点哦，但是中间的某个位置可能能够达到。

时间复杂度 $O(n)$，空间复杂度 $O(1)$ 。

## 代码
### 动态规划+正推（c++）
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) return false;
            if (i+nums[i] >= n-1) return true;
            for (int j = i+1; j <= i+nums[i]; ++j) {
                dp[j] = 1;
            }
        }
        return false;
    }
};
```

### 动态规划+倒推（c++）
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            if (i+nums[i] >= n-1) {
                dp[i] = 1;
                continue;
            }
            for (int j = i+1; j <= i+nums[i]; ++j) {
                dp[i] |= dp[j];
                if (dp[i]) break;
            }
        }
        return dp[0];
    }
};
```

### 贪心+正推（c++）
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxx) return false;
            maxx = max(maxx, i+nums[i]);
        }
        return maxx >= n-1;
    }
};
```

### 贪心+倒推（c++）
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), minn = n-1;
        for (int i = n-2; i >= 0; --i) {
            if (i+nums[i] >= minn) minn = i;
        }
        return !minn;
    }
};
```