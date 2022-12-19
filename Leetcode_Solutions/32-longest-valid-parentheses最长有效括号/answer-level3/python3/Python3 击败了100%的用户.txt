![1569050148(1).png](https://pic.leetcode-cn.com/d4c3e612a00fa1ab5384671ed84f079dbfdb51e9e50464d1bd6d283b4db9afeb-1569050148\(1\).png)
用两个变量l和r记录左括号和右括号的次数
当r=l时记录长度（2r）
考虑到最后r<l时也满足要求，把字符串倒过来再遍历一次
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        l=r=0
        max=0
        for i in s:
            if i=='(':
                l+=1
            else:
                r+=1
                if r==l:
                    t=r*2
                    if t>max:
                        max=t
                elif r>l:
                    l=r=0
        l=r=0           
        for i in s[::-1]:
            if i==')':
                l+=1
            else:
                r+=1
                if r==l:
                    t=r*2
                    if t>max:
                        max=t
                elif r>l:
                    l=r=0
        return max
```
