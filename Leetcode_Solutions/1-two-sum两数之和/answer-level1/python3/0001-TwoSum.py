### 解题思路
这道题可以理解为在给定的数组里找出满足二元一次方程a+b=target的解，且题目已经明确解唯一。
那么在没有其他约束的条件下，我们无法避免这样一次循环，即：假设a=数组第1个元素，计算b=target-a，判断b是否在该数组中，如在，访问b获得其对应下标index，并返回[0,index]，循环结束；若不在，则假设a=数组第2个元素，继续重复上述步骤。
剩下的问题是：如何通过“访问b获得对应下标index”？可以建立key（b）-value（index）的关系，对于这道题这个关系只有一对。


### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map={}
        for index, num in enumerate(nums):
            if target-num in hash_map:
                return [hash_map.get(target-num),index]
            hash_map[num]=index

```