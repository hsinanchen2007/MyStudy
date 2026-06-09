### 解题思路
我的想法是先遍历J中的元素，通过调用count函数来求出J中每个元素在S中出现的次数，但是本解的时间复杂度O(n),x性能上不是很好

### 代码

```python
class Solution(object):
    def numJewelsInStones(self, J, S):
        if len(J) <= 50 and len(S) <= 50:
            total = 0
            for i in range(0,len(J)):
                if S.count(J[i]) != 0:
                   total+=S.count(J[i])
            return total

            

```