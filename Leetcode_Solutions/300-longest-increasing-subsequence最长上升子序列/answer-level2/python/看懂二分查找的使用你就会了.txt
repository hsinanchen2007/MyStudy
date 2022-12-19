### 解题思路
用一个数组ends保存最长递增序列为k的最小元素，如
```
nums        2 1 5 3 6 4 8 9 7
dp          1 1 2 2 3 3 4 5 4
```
```
endsindex 0 1 2 3 4 5 6 7 8 9         
ends        1 3 4 7 9
```

`ends`下标为`k`，表示原数组中最长递增序列长度为k的这些序列中，最小的元素是`ends[k]`。下标从1开始是为了方便。

初始，`dp[0] = 1，ends[1] = nums[0]，right = 1（有效下标边界）`，当遍历`nums`中的数`x`时，在`ends`数组中利用二分查找第一个大于等于x的数（所在`ends`的下标`l`），（如果`ends`中存在这样一个数，返回所在`ends`下标；如果不存在，则在`right`右边。不过最后的下标都是`l`）

找到`l`下标之后，更新`ends[l]=x`，更新`dp[i]=l`（l是ends下标即最长长度），更新`right=max(l, right)`

**关键是明白二分查找的进阶版：在有序数组里查找`k`，如果存在，返回下标；如果不存在，返回它应该插入的位置的下标**

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        '''利用二分查找 进阶版，和一个ends数组，优化时间。
        '''
        n = len(nums)
        if n<2:
            return n
        dp = [0 for i in range(n)]
        ends = [0 for i in range(n+1)]
        right = 1
        ends[1] = nums[0]
        for i in range(1, n):
            l, r = 1, right
            while l<=r:
                mid = (l+r)//2
                if ends[mid]<nums[i]:
                    l = mid + 1
                else:
                    r = mid - 1
            ends[l] = nums[i]
            dp[i] = l
            right = max(l, right)
        return max(dp)
```


附：二分查找的两种能力
```python
    def binarySearch(self, A, k):
        '''二分查找 基础版
        在有序数组里查找k，如果存在，返回下标
                        如果不存在，返回-1
        '''
        n = len(A)
        if n==0:
            return -1
        if n==1:
            return 0 if A[0]==k else -1
        i, j = 0, n-1
        while i<=j:
            mid = (i+j)//2
            if A[mid]<k:
                i = mid + 1
            elif A[mid]>k:
                j = mid - 1
            else:
                return mid
        return -1
```
```python
    def binarySearch2(self, A, k):
        '''二分查找 进阶版
        在有序数组里查找k，如果存在，返回下标
                        如果不存在，返回它应该插入的位置的下标
        '''
        n = len(A)
        if n==0:
            return -1
        if n==1:
            return 0 if A[0]==k else -1
        i, j = 0, n-1
        while i<=j:
            mid = (i+j)//2
            if A[mid]<k:
                i = mid + 1
            else:
                j = mid - 1
        return i
```