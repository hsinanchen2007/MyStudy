### 解题思路
目前主流的解题思路有两种，它们的基础都是基于二分查找，毕竟题目要求时间复杂度为O(logn)。
方法一：
    1.先找到旋转数组中的旋转节点，比如说[4,5,6,1,2,3], 有人将6作为旋转点，有人将1做为旋转点，不同体现在第2步给函数中传递的参数不同，我是将6做为旋转节点P。
    2.既然找到了P，P将数组分为两部分，每个部分都有序，接下来只需要根据target与nums[0],nums[p],nums[lenth - 1]的大小关系分情况在两个区间内使用二分查找搜寻target。
方法二：
    不寻找旋转节点，每次求得中间节点mid后，mid将数组分为两部分，一部分是有序数组，一部分仍是旋转数组，比如说[4,5,6,7,**8**,9,1,2,3],8是中间节点mid，4,5,6,7为有序数组， 9,1,2,3为新的旋转数组。要做的就是分情况讨论序数组的情况（有mid决定），然后确定新的low和high的值。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        '''
        # 64 ms	13.6 MB
        直接利用二分查找找寻目标值，有点递归的意思。
        方法二思路：
        通过二分查思想找到中间节点，判断中间节点的值与数组首元素的大小关系，从而确定有序组的范围，因为中间节点不一定就是旋转节点，所以中间          节点将数组分为了两部分，一部分是旋转数组，一部分是有序数组。在有序数组中就利用正常使用二分查找找target，在旋转数组重复之前的步骤。

        '''
        if not nums: return -1

        low = 0
        high = len(nums) - 1
        
        while low <= high:
            mid = (high + low) // 2
            if nums[mid] == target: return mid
            if nums[low] <= nums[mid]: # low~mid是有序部分
                if nums[low] <= target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            # mid~high 是有序部分
            else:      
                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        
        return -1
        
        '''        
        这是二分查找的扩展，思路还是利用二分查找。
        方法一思路：
            1.用二分查找先找到旋转节点（也就是数组最大值）
            2.用二分查找找到目标值。
        # 36 ms	13.7 MB

        if len(nums) == 0: return -1
        if len(nums) == 1:
            if nums[0] == target:
                return 0
            else:
                return -1
        
        if nums[0] < nums[len(nums) - 1]:
            res = self.findT(nums, 0, len(nums) - 1, target)
        else:
            # 找到旋转节点的位置,注意，这个p的位置是数值大         
            # 发生改变时候较大的那个，比如 456123，nums[p] == 6
            p = self.findP(nums, 0, len(nums)-1)
            print(p)
            if p == -1: return -1
            res = -1
            if nums[p] == target: return p
            elif nums[0] == target:
                return 0
            elif nums[len(nums) - 1] == target:
                return len(nums) - 1
            elif nums[0] < target < nums[p]:
                res = self.findT(nums, 0, p, target)
            elif target < nums[0]:
                res = self.findT(nums, p+1, len(nums)-1, target)        

        return res

    def findP(self, array, low, high):
        while(low <= high):
            mid = (low + high ) // 2
            if array[mid] > array[mid + 1]:
                return mid
            if array[mid] < array[low]:
                high = mid - 1
            else:
                low = mid + 1
        
        return -1

    def findT(slef, array, low, high, target):
        while low <= high:
            mid = (low + high) // 2
            if array[mid] == target:
                return mid
            if array[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
        
        return -1
    '''

```