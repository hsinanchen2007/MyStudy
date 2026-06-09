### 解题思路
1. # 写在前面
题目点名要求logN，是一道比较基础的二分查找的题目，但是奈何本人水平不足，只会if-else满天飞的写法，算法思路还是比较清楚的，虽然代码不美观，但是掌握算法是比较关键的事情
2. #算法思路分析 
从中值开始查找，如果满足峰值要求`nums[i]>nums[i-1] and nums[i]>nums[i+1]`,那么这个就是峰值，如果有一个不满足，中值小于右值，说明峰值肯定在中值的右边，如果中值小于左值，峰值就在中值的左边，由此写出主体代码
3. #需要注意的点
我不知道`nums[i]=nums[n] = minus infinite`怎么表示，就要if-else写了，接下来希望去看一下各路大神怎么处理这个，本人水平不足就不讲解了


### 代码

```python
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left<=right:
            mid = (right+left)//2
            if mid+1<=right and mid-1 >=0:
                if nums[mid]>nums[mid+1] and nums[mid]>nums[mid - 1]:
                    return mid
                elif nums[mid]<nums[mid+1]:
                    left = mid+1
                elif nums[mid]<nums[mid-1]:
                    right = mid-1
            elif mid+1>right:
                if nums[mid]>nums[mid-1]:
                    return mid
                else:
                    right = mid-1
            else:
                if nums[mid]>nums[mid+1]:
                    return mid
                else:
                    left = mid+1
        return 0
```