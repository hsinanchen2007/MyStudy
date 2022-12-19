### 解题思路
不明白为什么分类是排序：3

字母异位词：两个str（长度大于等于2）字母元素相同，元素个数也相同，但位置不一致。

### 代码

```python3
from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):  # 长度不相同
            return False

        if len(s) == 0 and (len(t) == 0):  # 两个str都为空
            return True

        if set(s) != set(t):  # 元素不相同
            return False
        
        if len(s) == 1 and len(t) == 1:  # 只有一个元素都用例
            if s[0] == s[0]:
                return True
            else:
                return False
        
        sDict = Counter(s)
        tDict = Counter(t)

        for ele in set(s):
            if sDict[ele] != tDict[ele]:   # 元素个数不相同
                return False
         
        for i in range(len(s)):
            if s[i] == t[i]:
                continue
            else:
                return True


        

```