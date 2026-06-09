### 解题思路
归并递归思想。
左右两部分的逆序数，加上两部分总共的逆序数

代码如下

### 代码

```python3
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        if not nums:
            return 0
        def merge_order(nums):
            if len(nums) == 1:
                return 0, nums
            med = int(len(nums)/2)
            l_list = nums[:med]
            r_list = nums[med:]
            l_n, l_l = merge_order(l_list)
            r_n, r_l = merge_order(r_list)
            i_l = 0
            i_r = 0
            re = 0
            re_list = []
            while i_l < len(l_l) and i_r <len(r_l):
                if l_l[i_l]<=r_l[i_r]:
                    re_list.append(l_l[i_l])
                    i_l += 1
                else:
                    re_list.append(r_l[i_r])
                    re += len(l_l) - i_l
                    i_r += 1
            if i_l != len(l_l):
                re_list.extend(l_l[i_l:])
            if i_r != len(r_l):
                re_list.extend(r_l[i_r:])
            return re+l_n+r_n, re_list

        re, re_list = merge_order(nums)
        return re
            
```