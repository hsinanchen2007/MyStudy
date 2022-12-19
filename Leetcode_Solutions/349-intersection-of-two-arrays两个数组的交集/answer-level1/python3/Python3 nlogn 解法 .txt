### 解题思路
1. 对 nums1, nums2 分别排序
2. 设置指针1, 指针2分别指向 nums1, nums2 的第一个元素
3. 设置循环条件, 当指针1 和指针2 都小于各自数组长度时运行
4. 如果 指针指向的元素相等,则添加进返回 list; 此处要注意对重复元素要跳过 ,故指针加一
5. 如果 指针1 元素小, 则指针1 加 1; 否则指针2 加 1
6. 最后返回 list 即可

### 代码

```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        m, n  = 0, 0
        nums1.sort()
        nums2.sort()
        while m < len(nums1) and n < len(nums2):
            if nums1[m] == nums2[n]:
                ans.append(nums1[m])
                m += 1
                n += 1
                while m < len(nums1) and nums1[m] == nums1[m-1]:
                    m += 1
                while n < len(nums2) and nums2[n] == nums2[n-1]:
                    n += 1
            elif nums1[m] < nums2[n]:
                m += 1
            else:
                n += 1
        return ans
```