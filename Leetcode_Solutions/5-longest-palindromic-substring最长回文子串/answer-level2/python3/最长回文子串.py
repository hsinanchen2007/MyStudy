```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 暴力法
        max_len, result = float("-inf"), ""
        if len(s) == 1:
            result = s
        else:
            for i in range(len(s)):
                for j in range(i+1, len(s)):  # s[i:j]表示第i到j-1个字符串
                    if s[i:j] == s[i:j][::-1]:  # 翻转字符串
                        if j-i >= max_len:  
                            max_len = j-i
                            result = s[i:j]
        return result
```
上述方法会遇到下图错误，解决办法是将j的取值范围上限加1，见下一个代码，但是暴力法执行较长字符串时会超时，最终使用动态规划方法解决。
![搜狗截图20190514151835.png](https://pic.leetcode-cn.com/b07feae087f1f04295050dac2a6a0a39b07847fa1b16ea426828a03019bd092f-%E6%90%9C%E7%8B%97%E6%88%AA%E5%9B%BE20190514151835.png)
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 暴力法
        max_len, result = float("-inf"), ""
        if len(s) == 1:
            result = s
        else:
            for i in range(len(s)):
                for j in range(i+1, len(s)+1):  # s[i:j]表示第i到j-1个字符串
                    if s[i:j] == s[i:j][::-1]:  # 翻转字符串
                        if j-i >= max_len:  
                            max_len = j-i
                            result = s[i:j]
        
        return result
```

```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 动态规划法,将遍历到的字符作为回文串的结尾
        if len(s)<2 or s==s[::-1]:
            return s
        
        start, max_len = 0, 1
        for i in range(len(s)):
            odd = s[i-max_len-1:i+1]  # 子串字符数为奇数
            even = s[i-max_len: i+1]  # 子串字符数为偶数
            if i-max_len-1 >= 0 and odd == odd[::-1]:
                start = i-max_len-1
                max_len += 2
            elif i-max_len >= 0 and even == even[::-1]:
                start = i-max_len
                max_len += 1
        return s[start:start+max_len]

```