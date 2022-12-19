### 解题思路
- 先计算倒数第二层到倒数第一层的最短路径之和，更新倒数第二层的数值
- 再计算到数第三层到倒数第二层的最短路径之和，更新倒数第三层的数值
- 一直更新到顶层，顶层只有一个值，也就是整个三角形的最小路径之和

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        total_depth = len(triangle)-1
        cur_depth = total_depth - 1
        while cur_depth>=0:
            for index,val in enumerate(triangle[cur_depth]):
                triangle[cur_depth][index] = val + min(triangle[cur_depth+1][index],triangle[cur_depth+1][index+1])
            cur_depth = cur_depth - 1
        return triangle[0][0]
```