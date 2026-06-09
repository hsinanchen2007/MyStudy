### 解题思路 在循环中动态改变列表的大小真的安全吗？
此处撰写解题思路

### [代码](https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/)

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res, head = [0], 1
        for i in range(n):
            for j in range(2**(i) - 1, -1, -1):#range(len(res) - 1, -1, -1)
                res.append(head + res[j])
            head <<= 1
        return res

```