```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        a = 0
        i = 0
        re_s = ""
        for j in range(len(S)):
            if S[j] == "(":
                a +=1
            else:
                a -=1
            if a == 0:
                re_s += S[i:j+1][1:-1]
                i = j+1
        return re_s
```
执行用时 :44 ms, 在所有 python3 提交中击败了94.90%的用户
内存消耗 :13.8 MB, 在所有 python3 提交中击败了5.61%的用户