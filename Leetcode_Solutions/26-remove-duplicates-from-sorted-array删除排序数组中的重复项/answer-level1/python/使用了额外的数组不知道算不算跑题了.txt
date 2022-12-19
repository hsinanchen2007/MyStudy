### 解题思路
我是先把列表中所有不重复的元素放在set中，然后清空原列表后在把set中的元素添加到列表中。不知道算不算跑题了。
试了一下new=sets()的时间少于new=[]的时间，有知道原因的么，我没学过数据结构。。
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        new = set()     # 使用set的时间少于list
        for num in nums:
            if num not in new:
                new.add(num)
        for i in range(len(nums)):
            nums.pop()
        for n in new:
            nums.append(n)
        nums.sort()
        return len(nums)
```