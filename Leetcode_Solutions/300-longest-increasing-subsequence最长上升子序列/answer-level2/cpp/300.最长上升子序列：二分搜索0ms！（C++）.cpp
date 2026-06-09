### 0x00.博客推荐

本题解大部分参考此博客：[求最长上升子序列的三种经典方案](https://www.cnblogs.com/812-xiao-wen/p/10992613.html)。

博主分析的很详尽，可以好好阅读。本题解简要概括思路，并给出针对$Leetcode$的代码。

### 0x01.题意分析

经典老题，求数组$A$最长上升子序列（$Longest\ Increasing\ Subsequence,LIS$）。

### 0x02.动态规划

假设$dp[i]$表示以第$i$个数字结尾的$LIS$长度。则有状态转移方程：

$$dp[i] = 1+\max_{1\le j\lt i,A[j]\lt A[i]}{dp[j]}$$

这样就可以通过一个二重循环求解。复杂度：$O(n^2)$。

```cpp
int dp[10005];

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp[0] = 0;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int mx = 0;
            for (int j = 1; j < i; j++) 
                if (nums[j - 1] < nums[i - 1]) mx = max(mx, dp[j]);
            dp[i] = mx + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

### 0x03.树状数组

考虑将原数组排序，并保存每个数字对应的原下标。

按序做$dp$，则原状态转移方程中$A[j]\lt A[i]$的条件就自然满足了。接下来只需考虑求出下标小于$i$的$dp$数组的最大值。这可以利用一个树状数组实现。

注意排序时若$A[i]=A[j]$，则原下标大的排在前面。

复杂度：$O(nlogn)$，实际运行$8ms$。

```cpp
vector<int> nms;
int n;

int id[10005];
bool cmp(int a, int b) {
    if (nms[a] == nms[b]) return a > b;
    return nms[a] < nms[b];
}

int mx[10005];
int lowbit(int x) {return x & -x;}
void add(int p, int v) {for (int i = p; i <= 10000; i += lowbit(i)) mx[i] = max(mx[i], v);}
int get(int p) {
    int ret = 0;
    for (int i = p; i >= 1; i -= lowbit(i)) ret = max(ret, mx[i]);
    return ret;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        nms = nums;
        n = nms.size();
        nms.insert(nms.begin(), 0); // [1, n]
        
        for (int i = 1; i <= n; i++) id[i] = i;
        sort(id + 1, id + n + 1, cmp);
        
        memset(mx, 0, sizeof(mx));
        
        for (int i = 1; i <= n; i++) add(id[i], get(id[i] - 1) + 1);
        return get(n);
    }
};
```

### 0x04.二分搜索

这是最快的方法。

考虑改变$dp$数组的含义：$dp[i]$表示长度为$i$的上升子序列最小的末尾元素。可以想象$dp$数组一定是单调不减的。可以利用该性质二分搜索出最大的$dp[i]$使得$dp[i]\lt A[j]$。再利用$A[j]$更新$dp[i+1]$。

复杂度：$O(nlogn)$，实际运行$0ms$。

```cpp
int dp[10005];

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0x7f, sizeof(dp));
        dp[0] = 0x80000000;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int j = upper_bound(dp, dp + i, nums[i - 1] - 1) - dp;
            dp[j] = nums[i - 1];
            ans = max(ans, j);
        }
        return ans;
    }
};
```