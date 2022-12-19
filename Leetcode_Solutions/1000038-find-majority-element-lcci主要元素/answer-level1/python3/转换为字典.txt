### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        a = sorted(nums)
        b = list(set(a))
        c = {}
        d = -1
        for i in range(len(b)):
            c[b[i]]=nums.count(b[i])
            if  2*c.get(b[i])>len(nums) :
                     d = b[i]
        return d


```