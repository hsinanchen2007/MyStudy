#### 方法一： 暴力 【超时】

**思路**

遍历所有的分割方案去找分割数组的最大值。

**算法**

我们可以用深度优先搜索去生成所有的分割方案。对于数组中的每个元素，我们可以把它附加到之前的子数组上或者以这个数开始一个新的子数组（如果数组的长度不超过 `m`）。同时更新每个子数组的和。

```C++ []
class Solution {
public:
    int ans;
    int n, m;
    void dfs(vector<int>& nums, int i, int cntSubarrays, int curSum, int curMax) {
        if (i == n && cntSubarrays == m) {
            ans = min(ans, curMax);
            return;
        }
        if (i == n) {
            return;  
        }
        if (i > 0) {
            dfs(nums, i + 1, cntSubarrays, curSum + nums[i], max(curMax, curSum + nums[i]));
        }
        if (cntSubarrays < m) {
            dfs(nums, i + 1, cntSubarrays + 1, nums[i], max(curMax, nums[i]));
        }
    }
    int splitArray(vector<int>& nums, int M) {
        ans = INT_MAX;
        n = nums.size();
        m = M;
        dfs(nums, 0, 0, 0, 0);
        return ans;
    }
};
```

```Java []
class Solution {
    private int ans;
    private int n, m;
    private void dfs(int[] nums, int i, int cntSubarrays, int curSum, int curMax) {
        if (i == n && cntSubarrays == m) {
            ans = Math.min(ans, curMax);
            return;
        }
        if (i == n) {
            return;
        }
        if (i > 0) {
            dfs(nums, i + 1, cntSubarrays, curSum + nums[i], Math.max(curMax, curSum + nums[i]));
        }
        if (cntSubarrays < m) {
            dfs(nums, i + 1, cntSubarrays + 1, nums[i], Math.max(curMax, nums[i]));
        }
    }
    public int splitArray(int[] nums, int M) {
        ans = Integer.MAX_VALUE;
        n = nums.length;
        m = M;
        dfs(nums, 0, 0, 0, 0);
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n^m)$
把 `n` 个元素分成 `m` 份，共有 $\binom{n - 1}{m - 1}$ 种方案，也就是 $n^m$。

* 空间复杂度： $O(n)$
只需额外空间来存储这个数组。

### 方法二： 动态规划 【通过】

**思路**

这个问题满足无后向性的特点。我们可以用动态规划来解决它。

无后向性的特点意味着，一旦当前状态确定了，它就不会被之后的状态影响。在这个问题里面，如果我们在将 `nums[0..i]` 分成 `j` 份时得到了当前最小的分割数组的最大值，不论后面的部分怎么分割这个值不会受到影响。

**算法**

首先我们把 `f[i][j]` 定义为将 `nums[0..i]` 分成 `j` 份时能得到的最小的分割子数组最大值。

对于第 `j` 个子数组，它为数组中下标 `k + 1` 到 `i` 的这一段。因此，`f[i][j]` 可以从 `max(f[k][j - 1], nums[k + 1] +  ... + nums[i])` 这个公式中得到。遍历所有可能的 `k`，会得到 `f[i][j]` 的最小值。
 
整个算法那的最终答案为 `f[n][m]`，其中 `n` 为数组大小。

```C++ []

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        vector<int> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];
    }
};
```

```Java []

class Solution {
    public int splitArray(int[] nums, int m) {
        int n = nums.length;
        int[][] f = new int[n + 1][m + 1];
        int[] sub = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                f[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = Math.min(f[i][j], Math.max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];        
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n^2 * m)$
总状态数为 $O(n * m)$。为了计算每个状态 `f[i][j]`，需要遍历整个数组去找到那个最优的 `k`，这里会产生 $O(n)$ 次循环。所以总时间复杂度为 $O(n ^ 2 * m)$.

* 空间复杂度： $O(n * m)$
空间复杂度为状态总数，也就是 $O(n * m)$。

#### 方法三 二分搜索 + 贪心 【通过】

**思路**

我们很容易就能找到这个答案的一个性质：
> 如果我们找到了一种分割方案，使得最大的分割子数组和不超过 `x`，那么我们也能找到一种分割方案使得最大的分割子数组和不超过 `y`，其中 `y` 大于 `x`。

对于值 `x`，我们把这个性质定义为 `F(x)`。如果 `F(x)` 为真，那就意味着我们一定可以找到一种分割方案使得最大的分割子数组和不超过 `x`。 

我们让 `x` 的区间为 `负无穷大` 到 `无穷大`，一旦我们找到一个值 `x0`，使得所有的 `x < x0`，`F(x)` 都为假，所有的 `x >= x0`，`F(x)` 都为真。那么显然，这个 `x0` 就是我们要的答案了。

**算法**

我们可以用二分搜索来找到 `x0`。每次循环，我们让 `mid = (left + right) / 2`，如果 `F(mid)` 为假，那么我们接下来就去搜索 `[mid + 1, right]` 区间；如果 `F(mid)` 为真，那么我们接下来就去搜索 `[left, mid - 1]` 区间。

对于一个给定的 `x`，我们可以用贪心算法来计算 `F(x)`。我们用累计和 `sum` 来记录当前子数组的和，同时用 `cnt` 来记录子数组的数量。我们依次处理数组中的每个元素，对每个元素 `num`，如果 `sum + num <= x`，这就意味着当前的子数组没有超过限制。否则，就需要从当前元素 `num` 开始分割出一个新的子数组。

在完成遍历完整个数组之后，比较 `cnt` 和 `m` 的值。如果 `cnt <= m`，这就意味可以找到一种分割方案使得最大的分割子数组和不超过 `x`。否则，`F(x)` 一定为假。

```C++ []
#define LL long long
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        LL l = 0, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }
        LL ans =  r;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            LL sum = 0;
            int cnt = 1;            
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt ++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
```

```Java []
class Solution {
    public int splitArray(int[] nums, int m) {
        long l = 0;
        long r = 0;        
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }
        long ans = r;
        while (l <= r) {
            long mid = (l + r) >> 1;
            long sum = 0;
            int cnt = 1;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt ++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m) {
                ans = Math.min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (int)ans;      
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n * log(sum \ of \ array))$
二分搜索的时间复杂度为 $O(log(sum \ of \ array))$，其中 `sum of array` 是 `nums` 中所有元素之和。每次计算 `F(x)`，时间复杂度为 $O(n)$。

* 空间复杂度： $O(1)$