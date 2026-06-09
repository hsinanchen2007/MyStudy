### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        dict={}
        for i in nums:
            dict[i] = dict.get(i,0)+1
        k = int(len(nums)/3)
        ans = []
        for key in dict.keys():
            if dict[key]>k:
                ans.append(key)
        return ans
```