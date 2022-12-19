### 解题思路
利用栈的思想来判断，只要判断最后的2的值是一个有效括号，那么就可以直接pop()出去，最后判断一下栈里是否还有值。

### 代码

```

class Solution:
    def isValid(self, s: str) -> bool:
        kuohao = ["()","{}","[]"]
        if len(s)==0:  #空字符串可以被认为是正确字符串
            return True
            
        res = []*len(s)
        res.append(s[0])
        for i in range(1,len(s)):
            res.append(s[i])
            if "".join(res[-2:]) in kuohao:
                res.pop()
                res.pop()
        return not res 

```