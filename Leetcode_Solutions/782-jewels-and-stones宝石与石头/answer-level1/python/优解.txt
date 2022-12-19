### 解题思路
先判断S中的每一个元素是否在J中出现，出现返回1，否则返回0，并用sum函数把每次的结果求和，就求出所求结果

### 代码

```python
class Solution(object):
    def numJewelsInStones(self, J, S):
        return sum(s in J for s in S)

            

```