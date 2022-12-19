### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        array=[0 for _ in range(26)]
        for i in s:
            array[ord(i)-ord('a')]=array[ord(i)-ord('a')]+1
        for j in t:
            array[ord(j) - ord('a')] = array[ord(j) - ord('a')] - 1

        for ans in array:
            if ans!=0:
                return False
        return True
```