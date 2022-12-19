执行用时 : 32 ms, 在所有 python3 提交中击败了100.00%的用户
内存消耗 :13.7 MB, 在所有 python3 提交中击败了100.00%的用户

遍历一次字符串，首先判断是否非法字符，然后判断翻转后的字符与对应位置原字符是否相等，存在字符不想等即合法。

```
class Solution:
    def confusingNumber(self, N: int) -> bool:
        s=str(N)
        valid={'0':'0','1':'1','8':'8','6':'9','9':'6'}
        k=len(s)
        notSame=False
        for i in range(0,k):
            if s[i] not in valid:
                return False
            if valid[s[i]]!=s[k-1-i]:
                notSame=True
        return notSame
```
