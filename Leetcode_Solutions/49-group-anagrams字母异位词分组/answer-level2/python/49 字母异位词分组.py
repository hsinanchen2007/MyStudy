### 解题思路
字符串数组，用sort和dict解决。

### 代码

```python
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = {}
        n = len(strs)

        for i in range(n):
            key = sorted(strs[i])
            key = "".join(key)
            # print key
            if key not in res:
                res[key] = []
            if key in res:
                res[key].append(strs[i])

        val = [[] for i in  range(len(res.keys()))]
        # print res,res.keys(),len(res.keys()), val
        for i,key in enumerate(res.keys()):
            # print i, key, res[key][0], len(res[key])
            for j in range(len(res[key])):
                # print j, val[i]
                val[i].append(res[key][j])

        return val


```