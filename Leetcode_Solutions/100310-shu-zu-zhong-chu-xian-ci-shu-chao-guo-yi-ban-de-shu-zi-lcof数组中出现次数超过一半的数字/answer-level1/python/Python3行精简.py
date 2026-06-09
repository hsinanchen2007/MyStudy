### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        for c in set(nums):
            if nums.count(c)>len(nums)/2:
                return c

直接这么写，性能也还可以
![1.png](https://pic.leetcode-cn.com/7edc24afca28845b68d4719284d40fbe07329d8aad218484bf1ae068b2f3e8fc-1.png)

```