## 思路：

三种思路：

**思路 1：**

把每个字母当成回文串的中心

这里要考虑两种情况，回文串的长度为奇数或者偶数情况。

**思路 2：** 把每个字母当成回文串的结束

**思路 3：** 动态规划

`dp[j][i]` 表示字符串从 `j` 到 `i` 是否是为回文串，即当 `s[j] == s[i]` 如果 `dp[j+1][i-1]` 也是回文串，那么字符串从 `j` 到 `i` 也是回文串，即 `dp[j][i]` 为真。

-----

## 代码：

方法一：

```Python []
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        self.res = ""
        def helper(i,j):
            while i >= 0 and j < n and s[i] == s[j]:
                i -= 1
                j += 1
            if len(self.res) < j - i -1 :
                self.res = s[i+1:j]
        for i in range(n):
            helper(i,i)
            helper(i,i+1)
        return self.res
```

方法二：

```Python []
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        max_len = 1
        n = len(s)
        start = 0
        for i in range(1,n):
            even = s[i-max_len:i+1]
            odd = s[i - max_len-1:i+1]
            #print(even,odd)
            if i - max_len - 1 >= 0 and odd == odd[::-1]:
                start = i - max_len - 1
                max_len += 2
            elif i - max_len >=0 and even == even[::-1]:
                start = i - max_len
                max_len += 1
                
        #print(start,max_len)
        return s[start: start+max_len]
```

方法三：

```Python []
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s :
            return ""
        res = ""
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        max_len = float("-inf")
        for i in range(n):
            for j in range(i + 1):
                if s[i] == s[j] and (i - j < 2 or dp[j + 1][i - 1]):
                    dp[j][i] = 1
                if dp[j][i] and  max_len < i + 1 - j:
                    res = s[j : i + 1]
                    max_len = i + 1 - j
        return res

```
```Java []
class Solution {
    public String longestPalindrome(String s) {
       int n = s.length();
        String res = "";
        boolean[][] dp = new boolean[n][n];
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j <= i ;j ++){
                if(s.charAt(i) == s.charAt(j) && ( i - j < 2 || dp[j+1][i-1]))
                    dp[j][i] = true;
                if (dp[j][i] && (i - j + 1 > res.length())){
                    res = s.substring(j,i+1);
                }
            }
        }
        return res;
    }
}
```



