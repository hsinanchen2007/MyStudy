### 解题思路
When index is out of range, it returns IndexError
因此，在用list模拟一个stack的时候，要判断len(l)大于0才可以pop
那么加了这个条件，别忘记在append的时候，也得加字符不等于#才append


### 代码

```python3
class Solution:

    def get_clean_str(self, S: str) -> bool:
        l = []
        for s in S:
            if len(l)>0 and s == "#":
                l.pop()
            elif s!="#":
                l.append(s)
        return "".join(l)

    def backspaceCompare(self, S: str, T: str) -> bool:
        print(self.get_clean_str(S))
        print(self.get_clean_str(T))
        return self.get_clean_str(S) == self.get_clean_str(T)
    
```