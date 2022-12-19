### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        judge = 0
        magazine = list(magazine)
        for i in ransomNote:
            if i in magazine:
                judge +=1
                magazine.remove(i)
            else:
                return False
        if judge == len(ransomNote):
            return True
```