![image.png](https://pic.leetcode-cn.com/80b0283b57e2b663db58a8f34d08af530676483ad74a2ebf39f387f65517fa34-image.png)

### 解题思路
还是切片最高效
1、换一个思路，也就是将-k个元素添加到nums的开始，
2、注意，为什么是nums[lenth-k:]而不是nums[-k:]，因为是为了避免k=0的情况

### 代码
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ##用切片的方法：k就是将nums的最后k个数放在nums的开始位置即可
        lenth = len(nums)
        nums[:] = nums[lenth-k:]+nums[:lenth-k]
```
