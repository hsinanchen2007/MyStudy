"""解题思路"""
    利用Python特有的切片。
    第一步求出了k与nums长度的余数是为了避免出现k>len(nums)的情况出现
    然后在进行切片，把切下来的倒数k个元素放到列表最前面即可
    值得注意的是，在python中以nums = nums[-k:]+....的形式不能顺利赋值，
    需要以全切的方式nums[:]才可以。这个细节不是很清楚

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        if k == 0: return
        k = k%len(nums)
        nums[:] = nums[-k:] + nums[:-k]