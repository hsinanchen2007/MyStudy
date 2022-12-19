### 解题思路
先把字符串转化为列表，排序后判定两个列表是否相等即可。
初学者想法，简单粗暴

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a , b = list(s) , list(t)
        new1 = sorted(a,reverse = True)
        new2 = sorted(b,reverse = True)
        if  new1 == new2 :
            return True
        else:
            return False
```