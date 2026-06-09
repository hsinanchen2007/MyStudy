用快速排序法思想选第K大数，划分函数（左边比pivot处大，右边比其小）用来找到指定范围内pivot处元素（在这个范围）的位置，然后在初始数据选一个数，如果划分函数找到位置=K-1，找到，大于K，小于K再在相应范围里递归地找。

```python
from random import randint
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def partition(left,right,pivot): #pivot in [left,right]
            pivott =nums[pivot]  #!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!pivot其实是指下标，下标元素要搞清
            nums[pivot],nums[right] = nums[right],nums[pivot]
            index = left
            for i in range(left,right):
                if nums[i] > pivott:
                    nums[i],nums[index]=nums[index],nums[i]
                    index+=1
            
            nums[right]  ,nums[index]  = nums[index],nums[right] 
            return index
        def select(left,right,k):
            if left==right:
                return nums[left]   #!!!!!!!!!!!!!!!!元素非下标
            pivot = randint(left,right)
            ind = partition(left,right,pivot)
            if ind == k:
                return nums[ind]
            elif ind >k:
                return select(left,ind-1,k)
            else:
                return select(ind+1,right,k)
            
        return  select(0,len(nums)-1,k-1)           #heapq.nlargest(k, nums)[-1]

```


