### 解题思路
空间复杂度优化至O(n)
当前的路径数 =  左边的路径数 + 上边的路径数。
PS：只有这两条路径能到达当前路径。

在利用更新dp过程中的延迟性：
    i为当前计算到的位置：cur[i-1] 是左边的路径， cur[i] 是上边的路径
    所以cur[i] = cur[i-1] + cur[i]
![微信图片_20200208233020.jpg](https://pic.leetcode-cn.com/849c72350d6271bc59ee9eec8c8836038404783866678b4e11bacb911665eaf7-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200208233020.jpg)
### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        cur = [1]*m
        for i in range(1,n):
            for j in range(1,m):
                cur[j]  = cur[j-1] + cur[j]
        return cur[-1]
```