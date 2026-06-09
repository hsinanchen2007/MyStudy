方法一：倒序删除，其实就是类似双指针的原理，核心就是把控制循环的参数跟实际删除的索引区分开
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        for i in range(n):
            if nums[n - 1] == val:
                nums.remove(nums[n - 1])
            n = n - 1
        return len(nums)
```
方法二：交换位置，还是倒序来看，当往前走的a碰到相等的就跟最后面的值交换，后面被交换的位置指针k往前走一步，也就是说k右边的都是相等的需要移除的元素（实际上不应该叫交换，因为k右边的值并没有变过）
```
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        a = len(nums)
        k = a - 1
        for i in range(a):
            if nums[a - 1] == val:
                nums[a - 1] = nums[k]
                k = k - 1
            a = a - 1
        return k+1
```
