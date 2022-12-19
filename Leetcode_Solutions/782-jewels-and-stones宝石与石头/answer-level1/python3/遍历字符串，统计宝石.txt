```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        count=0
        for i in S:
            if i in J:
                count+=1
        return count

```
思路：遍历目标字符串，同时判断字符串中的字符是否属于宝石字符串，是的花在数量上加1即可。时间复杂度度为o(n)