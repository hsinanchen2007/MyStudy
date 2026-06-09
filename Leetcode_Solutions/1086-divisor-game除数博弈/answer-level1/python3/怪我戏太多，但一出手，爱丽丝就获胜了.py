### 解题思路
思路：求余数判定奇偶

### 代码

```python3
class Solution:
    def divisorGame(self, N: int) -> bool:
        #小爱是第一出手的，所以她是奇数局
        #大勃自然是偶数局出动
        #假定都是选择1，及时不是一，分布后实则没有区别
        #那么问题简化到判定奇偶了吗？
        #好的我们来试试
        return N%2 == 0

```