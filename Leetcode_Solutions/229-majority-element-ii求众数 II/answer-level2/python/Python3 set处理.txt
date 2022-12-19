### 解题思路
此处撰写解题思路
用set是最简单的思路:
    如果set里面的元素数目大于1/3则添加到列表里
### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        return [i for i in set(nums) if nums.count(i) > len(nums)/3 ]
        


```