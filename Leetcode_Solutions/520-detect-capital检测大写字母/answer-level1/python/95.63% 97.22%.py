### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word)==1:
            return True
        ALPHA='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        count=0
        for char in word:
            if char in ALPHA:
                count+=1
        if count==0 or count==len(word) or (count==1 and word[0] in ALPHA):
            return True
        return False

```