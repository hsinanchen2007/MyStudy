### 解题思路
1、分别创建两个字典，Key是字符、Value是出现次数；
2、如果Key都在两个字典，并且Value相同，则相同，否则不同；

### 代码

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        s_map = {}
        for i in s:
            if i not in s_map:
                s_map[i] = 0
            s_map[i] += 1
        t_map = {}
        for i in t:
            if i not in t_map:
                t_map[i] = 0
            t_map[i] += 1
        
        if len(s_map)!=len(t_map):
            return False
        
        for k,count in s_map.items():
            if k not in t_map or s_map[k]!=t_map[k]:
                return False
        return True

```