### 解题思路
利用python自带的list.count()函数。
先将数组转为集合类型，自动去重，然后挨个计算集合内的元素在数组内的数目，遇到大于n//2的直接输出。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        a=set(nums)
        n=len(nums)
        m=len(a)
        for i in range(m):
            temp=a.pop()
            k=nums.count(temp)
            if k>n//2:
                return temp

```