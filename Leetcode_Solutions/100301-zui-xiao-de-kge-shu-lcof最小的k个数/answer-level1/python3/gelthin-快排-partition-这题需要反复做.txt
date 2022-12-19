### 解题思路
同题目 [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

同题目 [面试题 17.14. 最小K个数](https://leetcode-cn.com/problems/smallest-k-lcci/)， 其题解 [gelthin-最坏情况partition-O(nk)](https://leetcode-cn.com/problems/smallest-k-lcci/solution/gelthin-zui-pi-qing-kuang-partition-onk-by-gelthin/)中分析了最坏情况下，所有元素都相同，partition每一次只能排出一个元素，效率为 O(n*k)


这题直接用 partition， 直至找到 pivot_index == k, 使其前的 k 个值小于 pivot, 后面的值大于 pivot.
不需要完全排完序再处理。

我之前的想法是找到第 k 小的元素，然后在把其他元素和它比较，保留比它小的。
但实际上， 如果使用 partition，找到第 k 小的元素时，arr 已经发生了改变。当我们判断这个元素为第 k 大，实际上就是其前面的元素都比它小，其后面元素都比它大。这里也已经知道了前 k 小的元素。

这里的循环 partition 相当于 selection 的复杂度，平均下来是 O(n) 的复杂度。 

T(n) = T(n/2) + O(n)

与带 selection 的 partition 有一些不同之处。按照 Huangyu 老师的 PPT 写的快排过于冗余，且复杂。
按照算法导论上有很好的代码模板。在 GitHub 上搜索 ACM 搜到了 quicksort 一个不错的[不错的实现](https://github.com/matthewsamuel95/ACM-ICPC-Algorithms/blob/master/Sorting/QuickSort/python/QuickSort.py)

#### 突然醒悟其实这就是基于partition 实现的 selection，不同之处只是在于: 返回第 k+1 个元素还是前 k 个元素。
因为做完 selection 后，这里的 partition 必然也实现了此效果。

基于 selection 的 partition, 可以用 O(n) 时间把 median 当做 pivot.



### 代码

```python3
class Solution:

    def extendLargeRegion(self, arr, pivot, lowVac, high):
        # lowVac 相当于 low
        j = high
        while j>lowVac:
            if arr[j] < pivot:
                arr[lowVac] = arr[j]
                return j
            j -= 1
        return lowVac # 没找到就返回lowVac

    def extendSmallRegion(self, arr, pivot, low, highVac):
        i = low
        while i<highVac:
            if arr[i] > pivot:
                arr[highVac] = arr[i]
                return i
            i += 1
        return highVac # 没找到就返回highVac

    def partition(self, arr, pivot, first, last):
        low = first
        high = last
        while low<high:
            highVac = self.extendLargeRegion(arr, pivot, low, high)
            lowVac = self.extendSmallRegion(arr, pivot, low+1, highVac)
            low = lowVac
            high = highVac - 1  # 注意到这对应 high-1, 对应 low+1
        return low # this is the splitPoint


    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 快速排序法：
        l = len(arr)
        if (l == 0) or (k>l):
            return
        if k == 0:
            return []
        #if k == l:  # 若不处理此，由于下面代码存在溢出风险，有bug
        #    return arr
        if l == 1:
            return arr

        left, right = 0, len(arr)-1
        target = k
        
        #while True: # bug  when k ==l, left index error

        while left<=right:
            pivot = arr[left]
            split_ind = self.partition(arr, pivot, left, right) # left, right, split_ind 都是原始 index
            arr[split_ind] = pivot

            if split_ind == target:   # 在 split_ind 左边有 k 个元素，全部不大于 pivot 
                break
            elif split_ind > target:
                left = left
                right = split_ind-1  # 不加此会陷入死循环
            else:
                left = split_ind+1  # 不加此会陷入死循环
                right = right

        return arr[:k]

```

### 代码2 更先进的 partition 代码，不输入 pivot 

```python3
class Solution:

    def partition(self, arr, first, last):
        pivot = arr[last]
        i = first
        for j in range(first, last):  # 不取 last
            if arr[j] < pivot:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
        
        arr[i], arr[last] = arr[last], arr[i]

        return i # this is the splitPoint

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 快速排序法：
        l = len(arr)
        if (l == 0) or (k>l):
            return
        if k == 0:
            return []
        if k == l:  # 不加此可能会有 bug
            return arr
        if l == 1:
            return arr

        left, right = 0, len(arr)-1
        while left <= right:   # 这里其实也相当于是二分法
            split_ind = self.partition(arr, left, right) # left, right, split_ind 都是原始 index
            if split_ind == k:   # 在 split_ind 左边有 k 个元素，全部不大于 pivot 
                break
            elif split_ind > k:
                right = split_ind-1  # 不-1 会陷入死循环
            else:
                left = split_ind+1  # 不 +1 会陷入死循环

        return arr[:k]
```