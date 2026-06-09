
在每次归并的时候就可以求出逆序数，比如7,6,3,2进行归并，7,6和3,2在进行排序的过程中很简单的求出这是逆序数为2，然后排序之后变成了6,7和3,2，再进行归并时候，因为左边(6,7)已经排好序了，所以当6大于3的时候，6后面的数字肯定都大于3，这样再相加即可

```
class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr = []
        
        self.res = 0
        # 最差n方
        def sort(nums):
            if len(nums) <= 1:
                return nums
            mid = len(nums) // 2
            left = sort(nums[:mid])
            right = sort(nums[mid:])

            return merge(left,right)

        def merge(left,right):
            temp = []
            l = 0
            r = 0
            while l < len(left) and r < len(right):
                if left[l] > right[r]:
                    temp.append(right[r])
                    self.res += len(left) - l
                    r += 1
                else:
                    temp.append(left[l])
                    l += 1 
            if l == len(left):
                temp += right[r:]
            if r == len(right):
                temp += left[l:]
            return temp 
        sort(nums)
        return self.res
```

