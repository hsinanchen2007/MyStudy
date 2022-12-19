### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        allsum = sum(A)
        if allsum%3:
            return False
        count， tmp = 0, 0
        for i in A:
            tmp += i
            if tmp == allsum//3 :
                count+=1
                tmp = 0
        return tmp ==0 and count>=3

```