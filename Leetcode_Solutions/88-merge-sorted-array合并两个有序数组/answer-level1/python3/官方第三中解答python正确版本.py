### 解题思路
官方第三种python代码直接复制进去显示越界
这里提供一个正确的
![微信截图_20191230112053.png](https://pic.leetcode-cn.com/0dd7ec9c5da00029fae1fb5ce237cd9ce9032f4e67df314143766c4d8ccdce1f-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191230112053.png)
### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        p1 = m - 1
        p2 = n - 1

        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[p1 + p2 + 1] = nums1[p1]
                p1 -= 1
            else:
                nums1[p1 + p2 + 1] = nums2[p2]
                p2 -= 1 
        if p2 > 0:
            nums1[: p1 + p2 + 2] = nums2[:p2+1]
        if p2 == 0:
            nums1[0] = nums2[p2]

```