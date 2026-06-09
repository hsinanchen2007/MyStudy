### 解题思路
此处撰写解题思路
如题
### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        del nums1[m:]
        if nums1:
            cur_1 = 0
            cur_2 = 0
            while (cur_1 <= len(nums1) - 1)&(cur_2 <= len(nums2) -1):
                if max(nums1) <= nums2[cur_2]:
                    nums1.append(nums2[cur_2])
                    cur_2 += 1
                elif nums1[cur_1] >= nums2 [cur_2]:
                    nums1.insert(cur_1,nums2[cur_2])
                    cur_2 += 1
                else:
                    cur_1 += 1
        else:
            for i in nums2:
                nums1.append(i)

```