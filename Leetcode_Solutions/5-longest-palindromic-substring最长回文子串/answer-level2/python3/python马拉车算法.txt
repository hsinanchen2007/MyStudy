### 解题思路
执行用时 :232 ms, 在所有 Python3 提交中击败了90.25%的用户

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        s = '#'.join(s) # s = '#'.join(item for item in s)
        s = '#' + s + '#'

        length = [1]*len(s)
        # 初始化length列表,以及要用的参数
        length[0], length[1], length[len(s)-1] = 1, 2, 1
        left, right, cen, mx = 0, 2, 1, 3
        for i in range(2, len(s) - 1):
            if i < right:
                # 利用之前求出来的对称点semmetry的length
                sym = 2*cen - i
                # s[i] == '#'
                if length[sym] == 1:
                    length[i] = 1
                # s[i]对称的字符的回文串在[left, right]里面
                elif sym - (length[sym] - 1) > left:
                    length[i] = length[sym]
                else:
                    l, r = 2*i - right, right
                    while l >= 0 and r < len(s) and s[l] == s[r]:
                        l -= 1
                        r += 1
                    length[i] = r - i
                    if r - l - 1 >= mx:
                        mx = r - l - 1
                        cen = i
                        left = l + 1
                        right = r - 1
            else:
                l, r = i-1, i+1
                while l >= 0 and r < len(s) and s[l] == s[r]:
                    l -= 1
                    r += 1
                length[i] = r - i
                if r - l -1 >= mx:
                    mx = r - l -1
                    cen = i
                    left = l + 1
                    right = r - 1

        # print(s, length)
        return s[left:right+1].replace('#', '')
```