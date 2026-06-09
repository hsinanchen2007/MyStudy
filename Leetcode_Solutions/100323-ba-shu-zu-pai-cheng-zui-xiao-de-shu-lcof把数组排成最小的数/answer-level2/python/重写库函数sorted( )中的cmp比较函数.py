### 解题思路
重写库函数sorted（）中的比较规则
sorted(iterable, cmp=None, key=None, reverse=False)
cmp表示比较函数，内有两个参数，要遵循规则：大于，返回1；小于，返回-1；等于，返回0
时间复杂度Nlog(n)
或者自己实现排序（冒泡，插入，选择，归并，快速，，，）

### 代码

```python
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums: return []
        for i in range(len(nums)):
            nums[i]=str(nums[i])
        def compare(a,b):
            if a+b<b+a:
                return -1
            elif a+b>b+a:
                return 1
            else:
                return 0
        nums=sorted(nums,cmp=compare)
        return ''.join(nums)

```