### 解题思路
此处撰写解题思路

### 代码
### 方法一：快速排序
```python []
class Solution:
    def partition(self, nums, l, r):
        pivot = nums[l]
        while l < r:
            while l < r and pivot <= nums[r]:
                r -= 1
            nums[l] = nums[r] 
            while l < r and nums[l] <= pivot:
                l += 1 
            nums[r] = nums[l]
        nums[l] = pivot
        return l
    def random_partition(self, nums, l, r):
        i = random.randint(l, r)
        nums[i], nums[r] = nums[r], nums[i]  
        return self.partition(nums, l, r)
    def quickSort(self, nums, l, r):
        if l < r:
            k = self.random_partition(nums, l, r)
            self.quickSort(nums, l, k-1)
            self.quickSort(nums, k+1, r)
    def sortArray(self, nums: List[int]) -> List[int]:
        self.quickSort(nums, 0, len(nums)-1 )
        return nums

```





### 方法三：归并排序
思路

归并排序利用了分治的思想来对序列进行排序。对一个长为 n 的待排序的序列，我们将其分解成两个长度为 n/2的子序列。每次先递归调用函数使两个子序列有序，然后我们再线性合并两个有序的子序列使整个序列有序。


```python []
class Solution:

    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) == 1: 
            return nums
        mid = len(nums) // 2
        return merge(self.sortArray(nums[:mid]), self.sortArray(nums[mid:]))

    def merge(self, left, right):
        res = []
        while len(left) > 0 and len(right) > 0:
            if left[0] < right[0]:
                res.append(left.pop(0))
            else:
                res.append(right.pop(0))
        res += left
        res += right
        return res      
```
### 复杂度分析

时间复杂度：O(nlogn)。由于归并排序每次都将当前待排序的序列折半成两个子序列递归调用，然后再合并两个有序的子序列，而每次合并两个有序的子序列需要 O(n) 的时间复杂度，所以我们可以列出归并排序运行时间 T(n) 的递归表达式：

根据主定理我们可以得出归并排序的时间复杂度为 O(nlogn)。

空间复杂度：O(n)。我们需要额外O(n) 空间的 tmp 数组，且归并排序递归调用的层数最深为logn，所以我们还需要额外的 O(logn) 的栈空间，所需的空间复杂度即为 O(n+logn)=O(n)。

