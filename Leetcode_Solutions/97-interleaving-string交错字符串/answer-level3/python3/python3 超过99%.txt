### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/b3f3d420ff4e5fdb4d694d0d31897de8485b6b9d14d3883f5d3cc4ea7d2ad7de-image.png)
集合 暴力破解
### 代码

```python3
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2): return False
        dp = set()
        dp.add((s1, s2))
        for i in s3:
            temp = set()
            while dp:
                listStr = dp.pop()
                if listStr[0] and listStr[0][0] == i:
                    temp.add((listStr[0][1:], listStr[1]))
                if listStr[1] and listStr[1][0] == i:
                    temp.add((listStr[0], listStr[1][1:]))
            dp = temp
        return ('', '') in dp
```