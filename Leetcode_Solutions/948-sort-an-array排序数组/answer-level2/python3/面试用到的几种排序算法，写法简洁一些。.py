# 题意：对数组升序排序
```
输入：nums = [5,2,3,1]
输出：[1,2,3,5
```
# 代码

**1、计数排序**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        from collections import defaultdict

        def counter_sort(nums,key=lambda x:x):
            B,C = [], defaultdict(list)
            for x in nums:
                C[key(x)].append(x)  #  {1:1,2:2,......}
            for k in range(min(C), max(C) + 1):
                B.extend(C[k])
            return B
        res = counter_sort(nums)
        return res
```

**2、快排**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        first = 0
        last = n - 1
        self.quickSorthepler(nums,first,last)
        return nums

    def partition(self, alist, first, last):
        left = first
        right = last
        pivot = alist[first]
        while left < right:
            while left < right and alist[right] >= pivot:
                right -= 1
            alist[left] = alist[right]
            while left < right and alist[left] <= pivot:
                left += 1
            alist[right] = alist[left]
        alist[left] = pivot
        return left
    
    def quickSorthepler(self, alist, first,last):
        if first < last:
            pointmark = self.partition(alist,first,last)
            self.quickSorthepler(alist,first,pointmark-1)
            self.quickSorthepler(alist, pointmark + 1, last)

```

**3、归并排序 merge**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        res = []
        mid = len(nums) //2
        left, right = nums[:mid],nums[mid:]
        if len(left) > 1: left = self.sortArray(left)
        if len(right) > 1: right = self.sortArray(right)

        while left and right:
            if left[-1] >= right[-1]:
                res.append(left.pop())
            else:
                res.append(right.pop())
        res.reverse()
        return (left or right) + res  # 将剩余left或right中的数和res合并
```
**4、选择排序（超时）**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # selection sort 
        n = len(nums)
        for i in range(n):
            for j in range(i,n):
                if nums[i] > nums[j]:
                    nums[i],nums[j] = nums[j],nums[i]
                    #print(nums)
        return nums
```


**5、插入排序（超时）**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # insert sort 
        n = len(nums)
        for i in range(1,n):
            while i > 0 and nums[i-1] > nums[i]:
                nums[i-1],nums[i] = nums[i],nums[i-1]
                i -= 1
        return nums
```
**6、 堆排序**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        n = len(nums)
        def build_heap(nums, start, end):  # 建堆的同时调整堆
            newitem = nums[start]
            cur = start
            leftpos = 2 * cur + 1
            while leftpos < end:
                rightpos = leftpos + 1
                if rightpos < end and nums[rightpos] >= nums[leftpos]:
                    leftpos = rightpos
                if newitem < nums[leftpos]:
                    nums[cur] = nums[leftpos]
                    cur = leftpos
                    leftpos = 2 * cur + 1
                else:
                    break
            nums[cur] = newitem
        for i in reversed(range(n//2)):  # 建堆+调整
            build_heap(nums, i, n)
        for i in range(n-1,-1,-1):
            nums[0],nums[i] = nums[i],nums[0]  #排序
            build_heap(nums,0,i)  #调整
        return nums
```
**7 堆排序 递归的写法**
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        self.build_heap(nums,n)
        print(nums)
        
        for i in range(n-1,-1,-1):
            nums[0],nums[i] = nums[i],nums[0]  #排序
            self.heapify(nums,0,i)  #调整
        return nums
    # 递归写法
    def heapify(self, nums, startpos, endpos):
        if startpos >= endpos: return 
        c1 = startpos * 2 + 1
        c2 = startpos * 2 + 2
        max_index = startpos
        if c1 < endpos and nums[c1] > nums[max_index]:
            max_index = c1
        if c2 < endpos and nums[c2] > nums[max_index]:
            max_index = c2
        if max_index != startpos:
            nums[startpos], nums[max_index] = nums[max_index], nums[startpos]
            self.heapify(nums, max_index, endpos)
    def build_heap(self, nums, n):
        last_node = n-1
        parent = (last_node-1) // 2
        for i in range(parent, -1,-1):
            self.heapify(nums,i,n)
```
