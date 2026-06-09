### 解题思路
此处撰写解题思路
当两个串都为空时或比较出大小后结束，一个为空时，则其版本号为0

### 代码

```python
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        version1 += '.'
        version2 += '.'
        while version1 != "" or version2 != "":
            v1 = 0 if version1 == "" else int(version1[:version1.index('.')])
            v2 = 0 if version2 == "" else int(version2[:version2.index('.')])
            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1
            version1 = "" if version1 == "" else version1[version1.index('.')+1:]
            version2 = "" if version2 == "" else version2[version2.index('.')+1:]
        return 0
```