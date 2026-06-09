### 0x00.题目分析

给定数组$prices[0:n-1]$，要求$max(prices[j]-prices[i])$且$j>i$。

### 0x01.暴力

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, prices[j] - prices[i]);
        return ans;
    }
};
```

时间复杂度：$O(n^2)$。
空间复杂度：$O(1)$。只使用了常数个变量。

### 0x02.树状数组

从$n-1$向前枚举$j$，利用树状数组求出$prices[0:j-1]$的最小值。

注意树状数组下标一般是从$1$开始的。

```cpp
int mmin[30005];

int lowbit(int x) {return x & -x;}

void add(int p, int v) {for (int i = p; i <= 30000; i += lowbit(i)) mmin[i] = min(mmin[i], v);}

int get(int p) {
    int ret = 0x7f7f7f7f;
    for (int i = p; i >= 1; i -= lowbit(i)) ret = min(ret, mmin[i]);
    return ret;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        memset(mmin, 0x7f, sizeof(mmin));
        for (int i = 0; i < n; i++) add(i + 1, prices[i]);
        
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) ans = max(ans, prices[i] - get(i));
        return ans;
    }
};
```

时间复杂度：$O(nlogn)$。
空间复杂度：$O(n)$。有一个长度为n的$mmin$数组以及常数个变量。

### 0x03.一次遍历

从$0$向后枚举$j$，并时刻保存$prices[0:j-1]$的最小值。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mmin = -1;
        for (auto x: prices) {
            if (mmin != -1) ans = max(ans, x - mmin);
            if (mmin == -1 || mmin > x) mmin = x;
        }
        return ans;
    }
};
```

时间复杂度：$O(n)$。
空间复杂度：$O(1)$。
