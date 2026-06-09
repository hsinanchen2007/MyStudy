### 解题思路
此处撰写解题思路
very easy recurrent algorithm
for a list of [1,2,3,4,5]. Assuming we have the list of subsets of [2,3,4,5], the right answer is all subsets of [2,3,4,5] union the single-element-set [1] union the result ([s+[1] for s in subsets([2,3,4,5])])
### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums)==0:return [[]]
        temp=self.subsets(nums[1:])
        return [x+[nums[0]] for x in temp]+temp
```