更新了下题解，数据扩过了，时间百分比没啥参考性，两者最快都是304ms左右，都在柱状图峰值的左边。

![image.png](https://pic.leetcode-cn.com/7c8a412aa6808059b4cbcbab0143e5e324eb65ab21d7c802f4b826c2c74db85b-image.png)
![image.png](https://pic.leetcode-cn.com/55578a16b7cfb5995132e702856a7ee64b279a63d2c77ff1919755f2f3c05cf4-image.png)

手写版：

```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                return m
        return -1
```

系统函数版，在其他题目里用得到：

```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i = bisect.bisect(nums, target)
        return i - 1 if nums[i - 1] == target else -1
```
