### 解题思路
考虑一个有序区和一个无序区。每次选一个数，如果比后面的大，就交换位置，这样最大的数肯定会被换到最后（也就是进入有序区），一共置换n趟，每趟遍历一次无序区。效率不高，最好情况O(n)平均情况O(n^2)最坏情况O(n^2)

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1):  # i表示第n趟 一共n或者n-1趟
            exchange = False
            for j in range(len(nums)-i-1): # 第i趟 无序区[0, n-i-1]  j表示箭头 0~n-i-2
                if nums[j] > nums[j+1]:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
                    exchange = True
            if not exchange:
                break







```