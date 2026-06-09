### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        num=0
        for s in S:
            for j in J:
                if s == j:
                    num+=1
                    break
        return num

J="aA"
S="aAAbbbb"
solution=Solution()
print(solution.numJewelsInStones(J,S))

```