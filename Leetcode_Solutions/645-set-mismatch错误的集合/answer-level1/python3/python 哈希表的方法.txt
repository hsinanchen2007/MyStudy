### 解题思路
除了求和作差之外的另一种方法，求和的思路不太好想，哈希表容易想到

### 代码

```python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        from collections import Counter
        count=Counter(nums)
        rep=None
        missed=None
        for index,i in enumerate(nums):
            if index+1 not in count:
                missed=index+1
            elif count[i]==2:
                rep=i
            if rep and missed:
                break
        return [rep,missed]
                

```