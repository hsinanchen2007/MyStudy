### 解题思路
思路1：对每个字符串排序，排序之后若相同则说明是互为字符重排。时间复杂度是O(nlog(n))。
这里我就直接用sorted了，懒得写排序了。。。

class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return sorted(s1) == sorted(s2)
思路2：用哈希表，记录每个字符出现的字数，比较两个哈希表是否相同。时间复杂度是O(n)，但是需要额外使用O(n)的空间复杂度用来保存哈希表。

class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        d1, d2 = {}, {}
        for i in s1:
            if i not in d1.keys():
                d1[i] = 0
            else:
                d1[i] += 1
            
        for j in s2:
            if j not in d2.keys():
                d2[j] = 0
            else:
                d2[j] += 1
        
        return d1 == d2

第三种
from collections import Counter
return Counter(s1) == Counter(s2)  


### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if sorted(list(s1)) == sorted(list(s2)):
            return True
        else:
            return False
```