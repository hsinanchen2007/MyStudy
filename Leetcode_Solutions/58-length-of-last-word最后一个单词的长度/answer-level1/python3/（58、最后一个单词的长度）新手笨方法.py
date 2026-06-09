执行用时 :36 ms, 在所有 Python3 提交中击败了65.20%的用户
内存消耗 :13.7 M, 在所有 Python3 提交中击败了5.15%的用户
```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0:
            return 0
        s = s.strip()  # 返回去除首尾空格符后的字符串
        j = 0
        for i in range(len(s)-1,-1,-1):
            if s[i] == ' ':
                break
            j += 1
        return j
```
