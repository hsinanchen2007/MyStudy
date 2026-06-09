### 解题思路
从后找到不为从大到小的时候的元素，并于其后面大于它的元素交换
交换完成后，后面的元素重新排序
### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 不需要对list进行排序
        n = len(nums)
        i = n-1
        while i > 0:
            if nums[i] > nums[i-1]:    # 3 > 1, 进入循环
                for j in range(i,n):    # j = 1~2
                    #这个循环退出时，表示后面序列都比nums[i-1]大
                    if nums[j] <= nums[i-1]:   # 3>1 2>1
                        # 添加等号，避免交换与nums[i-1] 相等的元素，因为此时后面的列表为从大到小
                        # 所以交换更大一点的元素
                        nums[j-1], nums[i-1] = nums[i-1], nums[j-1]
                        nums = self.resort(nums, i)
                        return
                nums[n-1], nums[i-1] = nums[i-1], nums[n-1]
                nums = self.resort(nums, i)
                return
            i -=1
        nums.sort()

# [1,5,1]  n =3  i = 1,  j = 1~2

    def resort(self, alist, srart):
        """重新排序"""
        n = len(alist)
        i = srart
        j = n-1
        while i < j:
            alist[i], alist[j] = alist[j], alist[i]
            i +=1
            j -=1
        return alist




# [1,3,2]  i = 1,  i-1 = 0, j =1~2
# []

```