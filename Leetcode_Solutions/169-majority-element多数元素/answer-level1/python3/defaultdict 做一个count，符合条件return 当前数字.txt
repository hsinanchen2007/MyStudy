### 代码
O(N)
```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic = collections.defaultdict(int)
        for num in nums:
            dic[num]+=1
            if dic[num] > len(nums)/2:
                return num  
```