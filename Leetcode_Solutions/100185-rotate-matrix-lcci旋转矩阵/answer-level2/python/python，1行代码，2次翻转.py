### 解题思路
今天的题能让大家缓口气了……

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix[:] = [m[::-1] for m in zip(*matrix)]
```
欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
