### 解题思路
1.初始空数组表示矩阵
2.用数组中的值表示走到此位置的步数；显然第0行和第0列的元素都为1
3.由题意，显然nums[i][j] = nums[i-1][j]+nums[i][j-1]
4.循环，求出nums的所有值
5.返回最后一个值nums[-1][-1]

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        nums = [[None for i in range(n)] for i in range(m)]
        for i in range(m):
            nums[i][0] = 1
        for j in range(n):
            nums[0][j] = 1
        for i in range(1,m):
            for j in range(1,n):
                nums[i][j] = nums[i-1][j]+nums[i][j-1]
        return nums[-1][-1]

```
**加油！！！
人生的旅途就是这样，
用大把时间迷茫，在几个瞬间成长！**