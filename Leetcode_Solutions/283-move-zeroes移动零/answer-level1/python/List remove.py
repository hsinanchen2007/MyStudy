### 解题思路
Python List的删除操作有两大类，一类是根据索引值删除，一类是根据元素值删除。索引值删除会引发一个问题，就是当前面删除了元素，后面的索引对于新的List来说就无效了，而且最终的nums的元素个数也不再是初始情况下的len(nums)。所以尝试使用remove删除指定元素值的、List中的第一个元素。这样就不会出现索引值异常的问题。并且，在remove的过程中，每次记录count值，最后在nums后面append全部的0。

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = 0
        while 0 in nums:
            nums.remove(0)
            count+=1
        for i in range(count):
            nums.append(0)
```