### 解题思路
利用字典统计字符出现次数，然后每排一个字符其次数减1，直到所有字符次数为0.
![image.png](https://pic.leetcode-cn.com/659fe493b93b85833aa9b7bfe26f0bb634e63762badfb2a860439f1bf136f7d3-image.png)


### 代码

```python
class Solution(object):
    def sortString(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        hash_table = {}
        for s1 in s:
            if s1 in hash_table:
                hash_table[s1] += 1
            else:
                hash_table[s1] = 1
        if len(hash_table.keys()) == 1:
            return s
        ma = max(hash_table.values())
        s_new = []
        temp = sorted(list(hash_table.keys()))
        for i in range(ma):
            if i % 2 == 0:
                s_new += temp
                for s_key in temp[:]:
                    hash_table[s_key] -= 1
                    if hash_table[s_key] == 0:
                        temp.remove(s_key)
            else:
                s_new += temp[::-1]
                for s_key in temp[:]:
                    hash_table[s_key] -= 1
                    if hash_table[s_key] == 0:
                        temp.remove(s_key)
        res = ""
        for j in s_new:
            res += j
        return res
```