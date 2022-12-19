### 解题思路

我觉得这题解体思路很简单，不知道为什么题目的难易程度是`困难`——瞎标

结果：
![image.png](https://pic.leetcode-cn.com/52b4b0bfac59b3c0013db34ce61ac5f738b3af4954f3db977429b5db5dc72332-image.png)


**思路如下：**
* 1） 合并两个列表中的元素
* 2） 对列表中的元素进行排序，python中很方便，用sorted(list)
* 3）  判断列表长度是奇数还是偶数
* 4） 计算出中位数

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums = sorted(nums)
        if len(nums) % 2 == 0:
            idx = int(len(nums)/2)
            mid_num = (nums[idx-1] + nums[idx]) / 2
            return mid_num
        else:
            idx = len(nums)//2 
            mid_num = nums[idx]
            return mid_num
            
```