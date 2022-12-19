### 解题思路
题目描述：一个有序数组只有一个数不出现两次，找出这个数
要求以在 O(log n)时间复杂度和 O(1)空间复杂度中运行。
采用二分法，将原有的数组分成两小数组（两个数组包含数字个数的总和分别为一个奇数，一个为偶数）
如果切分后的数组，数字个数总和为偶数的数组都是成对存在，那么边界值（mid通过调整到偶数位置）与下一个值比较，如果相等则改变左边界值，否则改变右边界值

![image.png](https://pic.leetcode-cn.com/a3143095cf9964032ab795c7df3798d9c5d143bea9b7b93f7595b9160f64eec5-image.png)

### 代码

```python
class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right=0,len(nums)-1
        while left<right:
            # 中间数，0-mid的总数必定为奇数
            mid=left+(right-left)//2
            # 保证left/right/mid都在偶数位，使得查找区间大小一直是奇数
            if mid%2==1:
                mid -= 1
            # 判断边界来确定应该更改区间的左边界还是右边界
            if nums[mid]==nums[mid+1]:
                left=mid+2
            else:
                right=mid
        return nums[left]
```