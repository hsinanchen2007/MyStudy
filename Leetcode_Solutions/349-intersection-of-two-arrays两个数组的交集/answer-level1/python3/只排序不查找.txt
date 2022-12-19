### 解题思路
- 将2数组去重，并排序
- 遍历其中一个数组nums1
- 去掉nums2中比当前值小的数，记录相等的数
- 直到nums2为空或nums1，或当前值比nums2中最大值还大时，遍历完成

![图片.png](https://pic.leetcode-cn.com/a4b61547cf0415ad8e05d50ef68e8a2839a6c6108e18cb2502d684f441222e58-%E5%9B%BE%E7%89%87.png)

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1 = sorted(set(nums1))
        nums2 = sorted(set(nums2))
        res = []
        for num in nums1:
            while nums2 and num > nums2[0]:
                nums2.pop(0)
            if len(nums2) == 0 or num > nums2[-1]:
                break
            if num == nums2[0]:
                res.append(num)
                nums2.pop(0)
        return res
            

```