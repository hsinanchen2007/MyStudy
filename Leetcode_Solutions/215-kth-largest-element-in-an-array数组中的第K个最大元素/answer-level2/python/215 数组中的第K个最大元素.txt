### 解题思路
归并排序

### 代码

```python
class Solution(object):
    def merge(self, left, right):
        """合并两个已排序好的列表，产生一个新的已排序好的列表"""
        result = []  # 新的已排序好的列表
        i = 0  # 下标
        j = 0
        # 对两个列表中的元素 两两对比。
        # 将最小的元素，放到result中，并对当前列表下标加1
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1
        result += left[i:]
        result += right[j:]
        return result

    def mergesort(self, seq):
        """归并排序"""
        if len(seq) <= 1:
            return seq
        mid = len(seq) / 2  # 将列表分成更小的两个列表
        # 分别对左右两个列表进行处理，分别返回两个排序好的列表
        left = self.mergesort(seq[:mid])
        right = self.mergesort(seq[mid:])
        # 对排序好的两个列表合并，产生一个新的排序好的列表
        return self.merge(left, right)


    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        res = self.mergesort(nums)
        n = len(nums)
        return res[n-k]
```


```python
class Solution(object):

    def merge(self, left, right):
        m = len(left)
        n = len(right)
        i = 0
        j = 0
        res = [0] * (m+n)

        while i < m or j < n:
            if i == m and j < n:
                res[i+j] = right[j]
                j += 1
                continue
            elif j == n and i < m:
                res[i+j] = left[i]
                i += 1
                continue
            if left[i] <= right[j]:
                res[i+j] = left[i]
                i += 1
            else:
                res[i+j] = right[j]
                j += 1

        return res


    def mergeSort(self, nums):
        mid = len(nums) / 2
        if len(nums) <= 1:
            return nums
        left = self.mergeSort(nums[:mid])
        right =  self.mergeSort(nums[mid:])
        return self.merge(left, right)

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        res = self.mergeSort(nums)
        n = len(nums)
        return res[n-k]
```




### 解题思路
选择排序

### 代码

```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        n = len(nums)
        mindex = 0

        for i in range(n):
            mindex = i
            for j in range(i+1, n):
                if nums[j] < nums[mindex]:
                    mindex = j
            nums[mindex], nums[i] = nums[i], nums[mindex]

        return nums[n-k]
```


### 解题思路
冒泡排序

### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        n = len(nums)

        for i in range(n):
            for j in range(0,n-1-i):
                if nums[j] > nums[j+1]:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
        # print nums
        return nums
```


### 解题思路
快速排序

### 代码

```python
class Solution(object):
    def partition(self, arr,low,high): 
        i = ( low-1 )         # 最小元素索引
        pivot = arr[high]     
    
        for j in range(low , high): 
    
            # 当前元素小于或等于 pivot 
            if   arr[j] <= pivot: 
            
                i = i+1 
                arr[i],arr[j] = arr[j],arr[i] 
    
        arr[i+1],arr[high] = arr[high],arr[i+1] 
        return ( i+1 ) 
    
    # 快速排序函数
    def quickSort(self, arr,low,high): 
        if low < high: 
    
            pi = self.partition(arr,low,high) 
    
            self.quickSort(arr, low, pi-1) 
            self.quickSort(arr, pi+1, high) 

    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        n = len(nums)
        self.quickSort(nums, 0, n-1)
        # print nums
        return nums[n-k]
```



### 解题思路
堆排序

### 代码

```python
class Solution(object):
    def heapify(self, arr, n, i): 
        largest = i  
        l = 2 * i + 1     # left = 2*i + 1 
        r = 2 * i + 2     # right = 2*i + 2 
    
        if l < n and arr[i] < arr[l]: 
            largest = l 
    
        if r < n and arr[largest] < arr[r]: 
            largest = r 
    
        if largest != i: 
            arr[i],arr[largest] = arr[largest],arr[i]  # 交换
    
            self.heapify(arr, n, largest) 
    
    def heapSort(self, arr): 
        n = len(arr) 
    
        # Build a maxheap. 
        for i in range(n, -1, -1): 
            self.heapify(arr, n, i) 
    
        # 一个个交换元素
        for i in range(n-1, 0, -1): 
            arr[i], arr[0] = arr[0], arr[i]   # 交换
            self.heapify(arr, i, 0) 


    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        n = len(nums)
        self.heapSort(nums)
        # print nums
        return nums[n-k]

```