```
class Solution:
    #直接插入排序，TLE
    def InsertSort(self,nums):
        n = len(nums)
        for i in range(n):
            temp = nums[i]
            j = i - 1
            while j >= 0 and nums[j] > temp:
                nums[j+1] = nums[j]
                j -= 1
            nums[j+1] = temp
        return nums
    #二分插入排序，寻找插入位置时用二分查找,TLE
    def HInsertSort(self,nums):
        n = len(nums)
        for i in range(n):
            temp = nums[i]
            low = 0
            high = i - 1
            while low <= high: #二分查找
                mid = (high+low)//2
                if nums[mid] > temp:
                    high = mid - 1
                else:
                    low = mid + 1
            nums[high+2:i+1] = nums[high+1:i]
            nums[high+1] = temp
        return nums
    #希尔排序，也称缩小增量排序
    def ShellSort(self,nums):
        n = len(nums)
        dk = n // 2
        while dk >= 1:
            for i in range(dk,n):
                if nums[i] < nums[i-dk]:
                    temp = nums[i]
                    j = i - dk
                    while j >= 0 and temp < nums[j]:
                        nums[j+dk] = nums[j]
                        j -= dk
                    nums[j+dk] = temp  
            dk //= 2
        return nums
    #冒泡排序，TLE
    def BubbleSort(self,nums):
        n = len(nums)
        for i in range(n):
            flag = 0
            for j in range(n-1,i,-1):
                if nums[j-1] > nums[j]:
                    nums[j-1],nums[j] = nums[j],nums[j-1]
                    flag = 1
            if flag == 0:
                return nums
        return nums
    #快速排序，如下调用
    #def sortArray(self, nums: List[int]) -> List[int]:
        #return self.QuickSort(nums,0,len(nums)-1)
    def QuickSort(self,nums,l,r):
        n = len(nums)
        if l < r:
            m = self.partition(nums,l,r)
            self.QuickSort(nums,l,m)
            self.QuickSort(nums,m+1,r)
        return nums
    def partition(self,nums,l,r):
        m = nums[l]
        while l < r:
            while l < r and nums[r] >= m:
                r -= 1
            nums[l] = nums[r]
            while l < r and nums[l] <= m:
                l += 1
            nums[r] = nums[l]
        nums[l] = m
        return l
    #堆排
    def adjust(self,nums,n,index):
        l = 2 * index + 1
        r = 2 * index + 2
        mIdx = index
        if l < n and nums[l] > nums[mIdx]:
            mIdx = l
        if r < n and nums[r] > nums[mIdx]:
            mIdx = r
        if mIdx != index:
            nums[mIdx],nums[index] = nums[index],nums[mIdx]
            self.adjust(nums,n,mIdx)
    def HeapSort(self,nums):
        n = len(nums)
        for i in range(n//2 - 1,-1,-1):
            self.adjust(nums,n,i)
        for i in range(n-1,0,-1):
            nums[0],nums[i] = nums[i],nums[0]
            self.adjust(nums,i,0)
        return nums
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.HeapSort(nums)
```
