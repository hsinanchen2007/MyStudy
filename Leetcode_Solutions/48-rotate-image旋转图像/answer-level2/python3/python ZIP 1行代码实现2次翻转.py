### 解题思路
第一次zip实现矩阵转置，然后列表推导式实现每个子列表倒序输出。
注意matrix加冒号表示inplace赋值，类似的还有这个题：[289.生命游戏](https://leetcode-cn.com/problems/game-of-life/solution/pythonlie-biao-tui-dao-yi-shi-shuang-yi-zhi-tui-da/)

### 执行结果
![image.png](https://pic.leetcode-cn.com/a3a21c77b407cedaac10db652cf9ff71266bd5c0efe29b7b6b1878f90270787e-image.png)


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix[:] = [lyst[::-1] for lyst in zip(*matrix)]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)