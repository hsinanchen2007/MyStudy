### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        count_dict=dict()
        for num in nums:
            if num in count_dict:
                count_dict[num]+=1
            else:
                count_dict[num]=1
        for x in count_dict:
            if count_dict[x]==1:
                return x 

```