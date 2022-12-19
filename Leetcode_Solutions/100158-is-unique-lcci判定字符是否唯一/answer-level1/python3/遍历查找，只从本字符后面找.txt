### 解题思路
此处撰写解题思路
题目中没有说字符只有小写字母，所以用整数位来表示的是有问题

遍历每个字符，从它后面的串里找，找到就是false

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        N = len(astr)
        if N <= 1:
            return True

        if N == 2:
            return astr[0] != astr[1]
        
        for i in range(N - 2):
            c = astr[i]
            for j in astr[i+1:]:
                if c == j:
                    return False
        
        return True
```