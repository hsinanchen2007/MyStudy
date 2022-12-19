官方解法改为字典做，发现要快不少

```
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:        
        dic = {}
        for age in ages: dic[age] = dic.get(age, 0) + 1

        res = 0
        for A, numA in dic.items():
            for B, numB in dic.items():
                if not (B <= 0.5 * A + 7 or B > A or (B > 100 and A < 100)):
                    res += numA * numB - numA * (A == B)                    
        return res

```
