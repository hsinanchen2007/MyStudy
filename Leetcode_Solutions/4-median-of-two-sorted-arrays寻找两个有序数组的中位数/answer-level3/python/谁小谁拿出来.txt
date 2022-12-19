### 解题思路
就是两个list的第一个元素互相比较，谁小谁拿出来放在n_list里。最后只要有一个list空了就结束，然后把剩余的加在n_list最后。
最后算一下n_list的中位数。

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n_list = list()
        while nums1 and nums2:
            pop_elem = nums1.pop(0) if nums1[0] < nums2[0] else nums2.pop(0)
            n_list.append(pop_elem)
        n_list += nums1
        n_list += nums2
        n_len = len(n_list)
        if n_len%2 == 0:
            res = (n_list[int(n_len/2)-1]+n_list[int(n_len/2)])/2
        else:
            res = n_list[int((n_len-1)/2)]

        return res

```