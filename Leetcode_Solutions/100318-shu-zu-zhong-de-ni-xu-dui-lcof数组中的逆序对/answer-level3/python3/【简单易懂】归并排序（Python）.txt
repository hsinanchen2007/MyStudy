
首先我们可以使用暴力法，也就是$O(N^2)$将所有可能枚举出来，如果满足逆，则cnt+1，最后返回cnt即可。这种做法虽然时间复杂度很差，但是在面试的时候，也可以作为一种兜底算法，以及缓解紧张情绪的解法。

我们接下来介绍更广泛使用的，效率更高的解法`分治`。 我们进行一次归并排序，并在归并过程中计算逆序数，换句话说`逆序对是归并排序的副产物`。

> 如果不熟悉归并排序，可以先查下相关资料。 如果你直接想看归并排序代码，那么将的代码统计cnt部分删除就好了。

归并排序实际上会把数组分成两个有序部分，我们不妨称其为左和右，归并排序的过程中会将左右两部分合并成一个有序的部分，对于每一个左右部分，我们分别计算其逆序数，然后全部加起来就是我们要求的逆序数。 那么分别如何求解左右部分的逆序数呢？

首先我们知道归并排序的核心在于合并，而合并两个有序数组是一个[简单题目](https://leetcode-cn.com/problems/merge-sorted-array/description/)。 我这里给贴一下大概算法：


```python

def mergeTwo(nums1, nums2):
    res = []
    i = j = 0
    while i < len(nums1) and j < len(nums2):
        if nums1[i] < nums[j]:
            res.append(nums[i])
        else:
            res.append(nums[j])
    while i < len(nums1) :
        res.append(num[i])
        i += 1
    while j < len(nums1) :
        res.append(num[j])
        j += 1
    return res

``` 


而我们要做的就是在上面的合并过程中统计逆序数。
                  ️
比如对于左：【1，2，**3**，4】右：【**2**，5】。  其中i，j指针如图粗体部分。 那么 逆序数就是 mid - i + 1 也就是 3 - 2 + 1 = 2 即（3，2）和（4，2）。 其原因在于如果3大于2，那么3后面不用看了，肯定都大于2。
                ️
之后会变成：【1，2，**3**，4】右：【2，**5**】





```python
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        self.cnt = 0
        def merge(nums, start, mid, end):
            i, j, temp = start, mid + 1, []
            while i <= mid and j <= end:
                if nums[i] <= nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    self.cnt += mid - i + 1
                    temp.append(nums[j])
                    j += 1
            while i <= mid:
                temp.append(nums[i])
                i += 1
            while j <= end:
                temp.append(nums[j])
                j += 1
            
            for i in range(len(temp)):
                nums[start + i] = temp[i]
                    

        def mergeSort(nums, start, end):
            if start >= end: return
            mid = (start + end) >> 1
            mergeSort(nums, start, mid)
            mergeSort(nums, mid + 1, end)
            merge(nums, start, mid,  end)
        mergeSort(nums, 0, len(nums) - 1)
        return self.cnt
```

注意上述算法在mergeSort中我们每次都开辟一个新的temp，这样空间复杂度大概相当于NlogN，实际上我们完全每必要每次mergeSort都开辟一个新的，而是大家也都用一个。代码：


```python
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        self.cnt = 0
        def merge(nums, start, mid, end, temp):
            i, j = start, mid + 1
            while i <= mid and j <= end:
                if nums[i] <= nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    self.cnt += mid - i + 1
                    temp.append(nums[j])
                    j += 1
            while i <= mid:
                temp.append(nums[i])
                i += 1
            while j <= end:
                temp.append(nums[j])
                j += 1
            
            for i in range(len(temp)):
                nums[start + i] = temp[i]
            temp.clear()
                    

        def mergeSort(nums, start, end, temp):
            if start >= end: return
            mid = (start + end) >> 1
            mergeSort(nums, start, mid, temp)
            mergeSort(nums, mid + 1, end, temp)
            merge(nums, start, mid,  end, temp)
        mergeSort(nums, 0, len(nums) - 1, [])
        return self.cnt
```

**复杂度分析**
- 时间复杂度：$O(NlogN)$
- 空间复杂度：$O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
