### 解题思路
思路比较简单，一行一行处理，一步一步来就行，注释比较清楚，题目也比较简单

### 代码

```python3
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        # 遍历图像的每一行
        # 运算完存在res中
        res = []
        for line in A:
            # 现将它逆序翻转
            line.reverse()
            # 然后把每一位按位异或1
            line = [i^1 for i in line]
            # 存起来
            res.append(line)
        return res
```