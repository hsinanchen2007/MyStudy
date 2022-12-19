
我们可以简单地使用线性的时间来解决，但是如果这是面试，恐怕不能通过。由于数组是有序的，尽管是分段有序，我们仍然考虑使用二分法。


我们将数组分成左右两部分，并且左右两部分分别有序。

- 初始化左右指针l和r，分别指向首尾元素。
- 我们每次取中间mid
- 如果 nums[mid] > nums[r]，说明mid在左侧有序部分，我们排除mid左侧（包括mid）所有元素
![](https://pic.leetcode-cn.com/758addad1d1b53bc20a67afcd3e86878dee55950204b56148bccf2ccefe95093.jpg)
- 如果 nums[mid] < nums[r]，说明mid在右侧有序部分，我们排序mid右侧（不包括mid） 所有元素
![](https://pic.leetcode-cn.com/dc46b8cfa327a212b1633800d9b83c6cd5c3f37f37f26bd1c3a85faf4f4cdee0.jpg)
- 如果 nums[mid] == nums[r]，我们只需要右侧指针左移一位即可。
![](https://pic.leetcode-cn.com/872559c3b6b334e2965ea4338ce2bd7531a1fc8a26a9360035716f86b6f8f280.jpg)
注意我们绝对不会错过最小值。我们反过来想，如果我们错过了最小值说明r就是唯一的最小值，这和nums[mid] == nums[r]矛盾。


```python
class Solution:
    def minArray(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        while l < r:
            mid = (l + r) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            elif nums[mid] < nums[r]:
                r = mid
            else:
                r -= 1
        return nums[r]
```

**复杂度分析**

- 时间复杂度：$O(logN)$，最坏的情况是数组全部元素相等，那么时间复杂度退化到$O(N)$
- 空间复杂度：O(1)

> 注意：我们求解的是最小值，但是不一定是旋转点。




欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
