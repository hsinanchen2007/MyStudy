### 解题思路
和杨辉三角I题思路相同
![image.png](https://pic.leetcode-cn.com/e7e114b19282414e609d9199561161672fdd1ce07be497f3c8a8771b15b33993-image.png)

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        for i in range(2, rowIndex + 2): # 第一行[1]已经定义，题目描述的输入3实际上是第四行（或者说[1]为第0行）
            temp = [1] * i
            for j in range(1, i-1):
                temp[j] = res[j-1] + res[j]
            res = temp
        return res

```