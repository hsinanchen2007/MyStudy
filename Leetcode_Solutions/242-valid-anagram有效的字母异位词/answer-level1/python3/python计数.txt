### 解题思路
首先判断字符串s与t长度是否相同，若不相同直接返回False。
若相同，使用字典记录字母数，用两个字典分别记录s与t中出现的字符及次数
最终，判定两字典是否相同，相同返回True，不同返回False。

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        d1 = {}
        d2 = {}
        for i,j in zip(s,t):
            if i not in d1:
                d1.update({i:1})
            else:
                d1[i] += 1
            if j not in d2:
                d2.update({j:1})
            else:
                d2[j] += 1
        if d1 == d2 :
            return True
        else:
            return False 

```