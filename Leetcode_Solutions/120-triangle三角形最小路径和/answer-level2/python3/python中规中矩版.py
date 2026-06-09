### 解题思路
就是照着给定条件，一行一行求解即可，单独处理每一行的的首位两个边界条件。

### 结果
![image.png](https://pic.leetcode-cn.com/f2870d3c267f37d13ebf057103bbc2433d0cc9d69d3740ab7a096f0c56645268-image.png)

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0
        n = len(triangle)
        s = [triangle[0][0]]*n
        for l in range(1, n):
            t = [0]*n
            t[0] = s[0]+triangle[l][0]
            for i in range(1, l):
                t[i] = min(s[i-1], s[i]) + triangle[l][i]
            t[l] = s[l-1] + triangle[l][l]
            s = t
        return min(s)

```