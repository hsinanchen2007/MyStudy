# 一、思路：

将每一行转换为set，再求其交集，最后返回交集中的最小值，如果交集为空，则返回-1

# 二、代码：

```
class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        s = set(mat[0])
        
        for i in mat[1:]:
            s = s & set(i)

        return min(s) if s else -1
```
