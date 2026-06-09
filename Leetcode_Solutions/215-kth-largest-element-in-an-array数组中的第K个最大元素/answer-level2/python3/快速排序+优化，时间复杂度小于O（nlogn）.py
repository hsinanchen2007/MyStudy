**解题思路：**要求查找第k个元素，容易想到可以先用库函数sort（）排序，再返回第k个元素。时间会很快（因为python底层优化），但理论上是O（nlogn）的复杂度。如果使用快排并加以优化，可以优化时间复杂度：
——————————————————————————————————————————————————————————————————————————————————————————————————————————
（1）利用快排算法，将nums分成大于和小于nums[0]的左右两侧，并得到调换位置的坐标；
（2）由于题目只要求返回第k个元素，所以不需要对左右两侧都递归排序，只需要通过比较k和调换元素坐标的大小，递归查找其中一侧；

## 示例代码

    def findKthLargest(self, nums: List[int], k: int) -> int:
        #考虑边界条件：
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            if nums[0] < nums[1]:
                nums[0], nums[1] = nums[1], nums[0]
            return nums[k-1]
        
        #快速排序算法：
        i = 1
        j = len(nums) - 1
        while i < j:
            while nums[i] >= nums[0] and i < j:
                i += 1
            while nums[j] < nums[0] and j > i:
                j -= 1
            if i == j:
                break
            nums[i], nums[j] = nums[j], nums[i]
        #分情况讨论：
        if nums[i] >= nums[0]:
            nums[i], nums[0] = nums[0], nums[i]
            if i == k-1:
                return nums[i]
            #递归调用
            elif i > k-1:
                res = self.findKthLargest(nums[0:i],k)
            else:
                res = self.findKthLargest(nums[i+1:],k-i)
        else:
            nums[i-1], nums[0] = nums[0], nums[i-1]
            if i-1 == k-1:
                return nums[i-1]
            elif i-1 > k-1:
                res = self.findKthLargest(nums[0:i-1],k)
            else:
                res = self.findKthLargest(nums[i:],k-i)
        return res
