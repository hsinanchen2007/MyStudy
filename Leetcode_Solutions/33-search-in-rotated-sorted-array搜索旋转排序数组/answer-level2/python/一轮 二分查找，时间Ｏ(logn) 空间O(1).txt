### 解题思路
1. 第一次接触旋转数组，都没有弄明白啥是旋转数组，一脸懵逼。然后采用顺序查找法O（N）提交，打败了双90%,即第一次提交的AC代码
2. 本着练习的目的，了解 [算法旋转数组](https://www.cnblogs.com/caoxinyu/p/10568496.html) 
3. 一轮 二分查找，时间Ｏ(logn) 空间O(1)
    1. 本质上仍然是一个二分查找，关键点在于判定 target 在那个半区
    2. 可知，任何一次二分,[left,mid] or [mid,right] 有一个半区是有序的
    3. 判定有序的方法就是 区间头 <= 区间尾 即 nums[left] <= nums[mid] 或者 nums[mid] <= nums[right]
    4. 再通过判定target是否在 有序半区中,来进行下一次二分
4. 举例:
    1. 如果[left,mid] 有序,而 nums[left] <= target <= nums[mid],证明 target在[left,mid]中
    2. 反之在[mid,right]中,从而进行下一次划分
    3. 跳出循环的条件:left == right
    4. 不断缩小区间直到只剩下一个
    5. 如果 nums[left] == target 则返回left,反之则不存在,返回-1
5. 分析：
    1. 时空符合题意


### 代码

```python
class Solution(object):
    
    
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 1:
            return -1

        res = self.binary_search(nums, 0, len(nums)-1, target)
        return res 

    def binary_search(self, nums, l, h, tar):
        if (l > h):
            return -1
        mid = (l + h) // 2
        if tar == nums[mid]:
            return mid 
        if nums[mid] < nums[h]: ## nums[mid:high] ordered...
            if nums[mid] < tar and nums[h] >= tar: ### in the ordered half_list
                return self.binary_search(nums, mid+1, h, tar)
            else: ### in the not ordered half_list ...
                return self.binary_search(nums, l, mid-1, tar)
        else:  ## nums[l:mid] ordered...
            if nums[l] <= tar and nums[mid] > tar: ### in the ordered half_list
                return self.binary_search(nums, l, mid-1, tar)
            else: ## in the not ordered half_list...
                return self.binary_search(nums, mid+1, h, tar)

```