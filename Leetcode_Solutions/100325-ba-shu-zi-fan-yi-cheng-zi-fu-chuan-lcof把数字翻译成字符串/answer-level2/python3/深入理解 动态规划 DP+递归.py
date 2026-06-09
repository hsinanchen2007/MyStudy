### 方法一：动态规划
这是一道典型的动态规划题目。对于一个数 `num[i]`，我们有两种选择：
- 只翻译自己；
- 和前面的数字组合翻译，前提是组合的数在 $10-25$ 之间。

我们可以用 $dp(i)$ 表示前 $i$ 个数字的翻译方法数。根据以上两种选择，我们进行如下分析：

1. *如果只翻译自己，比如 $12345$，如果 $5$ 单独翻译，那么方法数与 $1234$ 是一样的， $dp(i)=dp(i-1)$。
2. 如果和前面的数字组合，比如 $1235$，如果 $35$ 组合翻译，从两方面考虑：
    - $35$ 看成一个整体，虽然加了 $5$ 但是和没加是一样的，状态 $dp(i)=dp(i-1)$；
    - $35$ 组合就意味着不能再组合了，相当于条件 $1$ 中的单独翻译自己，方法数与 $12$ 是一样的。这时 $dp(i)=dp(i-2)$
    - 以上两种情况相加即可。

故状态转移函数为：

$$dp(i)=
\begin{cases}
dp(i-2)+dp(i-1)& \text{前面两个数在1--25之间}\\
dp(i-1)& \text{$else$}
\end{cases}$$

再考虑边界条件：
$$dp(0)=dp(1)=1$$
**注意**：条件 $1$ 星号处不是 $dp(i)=dp(i-1)+1$。比如 $12$ 如果 $2$ 单独翻译，$12$ 只有一种翻译方法。
#### 代码

```python []
class Solution:
    def translateNum(self, num: int) -> int:
        str_num = str(num)
        n = len(str_num)
        dp = [1 for _ in range(n + 1)] 
        for i in range(2, n + 1):
            if str_num[i - 2] == '1' or \
            (str_num[i - 2] == '2' and str_num[i - 1] < '6'):
                dp[i] = dp[i - 2] + dp[i - 1]
            else:
                dp[i] = dp[i - 1]
        return dp[n]
```
#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(n)$。


### 方法二：递归

我们设置一个辅助函数用来计算所有可能组合，而在每一步中我们都会继续调用 $backtrack$ 这个函数模拟独立翻译和组合翻译的情形，并返回两个函数的返回值之和。

![幻灯片1.JPG](https://pic.leetcode-cn.com/a12a168d3c88812a1d49277324898b289bf35beb059da1a59397f66c4ad1a269-%E5%B9%BB%E7%81%AF%E7%89%871.JPG)

#### 代码
```python []
class Solution:
    def translateNum(self, num: int) -> int:
        def backtrack(s, idx):
            n = len(s)
            if idx == n: return 1
            if idx == n - 1 or s[idx] == '0' or s[idx:idx + 2] > '25':
                return backtrack(s, idx + 1)
            else:
                return backtrack(s, idx + 1) + backtrack(s, idx + 2)
        
        s = str(num)
        return backtrack(s, 0)
```

```C++ []
class Solution {
public:
    int backtrack(string& s, int idx){
        int n = s.size();
        if(idx == n) return 1;
        if(idx == n - 1 || s[idx] == '0' || s.substr(idx, 2) > "25")
            return backtrack(s, idx + 1);
        return backtrack(s, idx + 1) + backtrack(s, idx + 2);
    }
    int translateNum(int num) {
        string s = to_string(num);
        return backtrack(s, 0);
    }
};

```


#### 复杂度分析
- 时间复杂度：$O(2^n)$，树形递归的大小为 $O(2^n)$。
n
- 空间复杂度：$O(n)$，递归树的深度可以达到 $n$。

欢迎提供 c++ 代码
如有问题，欢迎讨论~