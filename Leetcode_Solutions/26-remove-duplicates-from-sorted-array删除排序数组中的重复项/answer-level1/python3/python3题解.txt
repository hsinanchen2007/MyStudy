### 解题思路1

执行用时 : 92 ms, 在所有 Python3 提交中击败了92.60%的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了99.24%的用户
双指针法：i慢指针,j快指针。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        L=len(nums)
        if L<2:
            return L
        i=0
        for j in range(1,L):
            if nums[i]!=nums[j]:
                i=i+1
                nums[i]=nums[j]
        for j in range(i+1,L):
            nums.pop()
        return i+1
```

### 解题思路2

执行用时 :124 ms, 在所有 Python3 提交中击败了35.65%的用户
内存消耗 :14.5 MB, 在所有 Python3 提交中击败了99.12%的用户
双下标遍历。i为慢下标，j为快下标。不同时都前移，相同时pop(j)。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        L=len(nums)
        if L<2:
            return L
        i=0
        j=1
        while j<len(nums):
            if nums[i]!=nums[j]:
                i=i+1
                j=j+1
            else:
                nums.pop(j)
        return i+1
```
