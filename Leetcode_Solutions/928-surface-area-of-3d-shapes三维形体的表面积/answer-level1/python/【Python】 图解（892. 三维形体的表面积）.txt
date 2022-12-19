## 思路

- 一个立方体的面积为 4 * 1 + 2 
![image.png](https://pic.leetcode-cn.com/449dad8809f74681e2a9cf6f0d54247cec0d5a0e66a5802953bdeb95f494c565-image.png)
- n 个立方体并排或者并列的面积为 $((4 * 1 + 2) - min(1,1)  * 2) * (n - 1) + 4 * 1 + 2$ (其中min(1,1)  * 2 是两个连一起导致的被隐藏的表面积)
> min(1, 1) 分别是相邻立方体之间的高度
![image.png](https://pic.leetcode-cn.com/cd52f0716ab60e0810fb498f77dc4705d901e7c17f978532b186fb8f44c8f875-image.png)
（如上就是min(1, 1)）
![image.png](https://pic.leetcode-cn.com/d6c855e4bb99da1aabac0812cf0632950a2ab68414307f0cc850142c1da43cae-image.png)
(如上就是min(1,2))



图示：

![](https://pic.leetcode-cn.com/778a31787d880b650ec70fd8273622d42f5551b0fdd1ab4a6cbe102711c051ed.jpg)

明白了上面的过程，代码就会水到渠成。

## 代码

```python
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] > 0:
                    ans += grid[i][j] * 4 + 2
                if i > 0:
                    ans -= 2 * min(grid[i][j], grid[i - 1][j])
                if j > 0:
                    ans -= 2 * min(grid[i][j], grid[i][j - 1])
        return ans
```
***复杂度分析***
- 时间复杂度：$O(N * N)$
- 空间复杂度：$O(1)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
