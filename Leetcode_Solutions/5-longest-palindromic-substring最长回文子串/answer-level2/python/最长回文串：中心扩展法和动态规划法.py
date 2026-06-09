### 解题思路
中心扩展法：
1. 字符串长度小于2的时候直接返回
2. 中心扩展的方法，需要注意的是，left最小是0，right最大是size-1，right>=left
   当right=left时，回文串的长度为奇数；当right=left+1是，回文串的长度是偶数
   此处spread函数返回了回文串的左侧索引和长度
   因为当s[left]和s[right]不相等时，left和right已经分别-1和+1了
   所以返回的左侧索引为left+1，长度为(right-1)-(left+1)+1
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        if size < 2:
            return s
        
        start = 0
        len_max = 1
        
        def spread(left, right):
            while left >= 0 and right < size and s[left] == s[right]:
                left -= 1
                right += 1
            return left+1, right-left-1
        
        for i in range(0, size-1):
            left_even, len_even = spread(i, i+1)
            left_odd, len_odd = spread(i, i)
            
            [start_current, len_current] = [left_even, len_even] if len_even > len_odd else [left_odd, len_odd]

                
            if len_current > len_max:
                len_max = len_current
                start = start_current
        return s[start: start+len_max]
            
```

### 解题思路
动态规划法
1. dp[i][j]=True表示字符串s[i: j+1]是回文串
   即s[i] = s[j]且其子字符串是回文串(dp[i+1][j-1]=True)且
2. 注意当s[i] = s[j]且字符串长度小于4的时候(j-i+1<4)的时候，直接可以得到是回文串的结论
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        if size < 2:
            return s

        dp = [[False for _ in range(size)] for _ in range(size)]
        start = 0
        max_len = 1

        for j in range(1, size):
            for i in range(0, j):
                # 如果首尾两个字符相同
                if s[i] == s[j]:
                    # 如果字符串长度小于等于3则一定是回文串
                    if j - i < 3:
                        dp[i][j] = True
                    # 如果字符串大于3 则判断子字符串是否是回文串
                    else:
                        dp[i][j] = dp[i+1][j-1]

                # 如果是回文串 记录字符串初始位置和长度
                if dp[i][j]:
                    if j - i + 1 > max_len:
                        start = i
                        max_len = j - i + 1
        return s[start: start+max_len]  
```