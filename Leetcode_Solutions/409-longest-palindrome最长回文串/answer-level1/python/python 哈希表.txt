### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        hashmap = {}
        for i in s:
            hashmap[i] = hashmap.get(i, 0) + 1
        count1,count2 = 0,0
        flag=False
        for key in hashmap:
            if hashmap[key] % 2 == 0:
                count1 += hashmap[key]
            elif hashmap[key] % 2 != 0:
                flag=True
                count2 += hashmap[key] - 1
        return count1+count2+1 if flag else count1
```