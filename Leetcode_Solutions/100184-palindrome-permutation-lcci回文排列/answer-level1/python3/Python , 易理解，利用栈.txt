主要思路就是设置一个栈来储存，如果栈里面没有该元素则添加，结果+1，否则删除该元素，结果-1.最后判断一下res <= 1？
```
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        n = len(s)
        res = 0
        cur = []
        s = sorted(s) #可以不排序，排序浪费时间
        for i in s:
            if i in cur:
                res -= 1
                cur.remove(i)
            else:
                cur.append(i)
                res += 1
        if res <= 1:
            return True
        else:
            return False
```

