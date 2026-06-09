### 解题思路
依次遍历数组元素，用变量分别储存数组最大元素，第二大元素以及最大元素的下标即可。

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums)<1:
            return -1
        max1=nums[0]
        mi=0
        max2=0
        for i in range(1,len(nums)):
            if nums[i]>max1:
                max2=max1
                max1=nums[i]
                mi=i
            elif nums[i]>max2:
                max2=nums[i]
        if max1>=2*max2:
            return mi
        else:
            return -1
```

![image.png](https://pic.leetcode-cn.com/2cac656c8b3c9f080f725232d3661d41a423a3a4fa5437af1cce475deb11ece9-image.png)
