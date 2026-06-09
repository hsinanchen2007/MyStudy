### 解题思路
此处撰写解题思路

### 代码
     

```python []
class Solution:
    def permutation(self, s: str) -> List[str]:
        if len(s) == 1: return [s]
        res = []
        for i, x in enumerate(s):
            n = s[:i] + s[i+1:]
            for y in self.permutation(n):
                res.append(x+y)
        return list(set(res))
```  
 思路解释：
```python []
class Solution:
    def permutation(self, s: str) -> List[str]:
        length = len(s)
        if length == 1: return [s] # 边界
        else:
            res = []
            for i in range(length):
                ch = s[i]   #取出s中每一个字符
                rest = s[:i] + s[i+1:]
                for x in self.permutation(rest): #递归
                    res.append(ch + x)  #将ch 和子问题的解依次组合
        return list(set(res))
```  