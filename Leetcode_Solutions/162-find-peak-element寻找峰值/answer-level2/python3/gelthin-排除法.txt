### 解题思路
此题关键在于把数组看出是一个序列， "负无穷<nums[0]?nums[1]?...nums[n-1]>负无穷" 提取成一个关于'>'和'<'的序列： <????????>，此序列必然有一个位置开始变换符号，需要搜索找到这个序列开始反号的某一个位置。

测试 mid = left + (right-left+1)//2
如果 nums[mid-1] < nums[mid], 那么原序列 [left, right] 可以替换成 [mid, right]
如果 nums[mid-1] > nums[mid], 那么原序列 [left, right] 可以替换成 [left, mid-1]

这里就是要注意，可能 mid-1 == -1 就可能会出现 bug。不过此题还好，因为 left 的更新是 left=mid，所以强制要求
mid = left + (right-left+1)//2 
这样恰好有 mid 永远不可能为 0。但有时候left 更新是 left=mid+1, 导致 mid= left + (right-left)//2,这里就需要考虑mid-1 ==-1 的问题。

在这种情况下，可以通过限制搜索空间来避免，比如说，原来是 [0,n-1], 把 0 和 n-1 作为特殊情况优先处理，就可以得到 [1,n-2]
情况。


### 代码

```python3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n==0:
            return
        if n==1:
            return 0

        if nums[0]>nums[1]:
            return 0
        if nums[n-1]>nums[n-2]:
            return n-1
        
        a, b = 1, n-2  # 搜索空间
        while a<b:
            mid = a + (b-a+1)//2
            if nums[mid-1]<nums[mid]: 
                a = mid
            else:
                b = mid-1
        return a


```