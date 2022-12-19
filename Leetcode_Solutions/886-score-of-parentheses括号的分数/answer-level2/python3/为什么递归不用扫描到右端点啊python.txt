### 解题思路
为什么递归不用扫描到右端点啊
瞎搞啦一个代码，能过
但是
有一点没有懂，r-1为什么，这样len已经减一啦，这样如果最后一个“)”反括号扫描不到吗，那b-=1就做不了啦啊
```
class Solution:
    def scoreOfParentheses(self, S: str) -> int:

        def score(l: int, r: int):
            if r - l == 1:
                return 1
            isBalance = 0
            for i in range(l,r):
                if S[i] == '(':
                    isBalance += 1
                elif S[i] == ')':
                    isBalance -= 1
                if not isBalance:
                    return score(l, i) + score(i+1,r)
            return 2 * score(l+1, r-1)
        l, r = 0, len(S)-1
        return score(l, r)
```