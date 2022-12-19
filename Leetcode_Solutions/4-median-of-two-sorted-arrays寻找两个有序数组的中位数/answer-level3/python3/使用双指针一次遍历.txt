### 解题思路
1. 使用双指针
2. 考虑到中位数要么出现在总size为偶数的两个数组中间
3. 要么出现在奇数的总size的最中间那个数
4. 所以只要依次从两个数组中开始取，只要取的数超过两个数组之和的一半，那么就肯定能通过数组下标算出来
5. 为了保证顺序，所以两个数组的取值，必须是紧密相邻的，如果一方的值小，那么这一方必须加快挪动速度

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        sz: int = len(nums1) + len(nums2)
        is_odd: bool = True
        if sz % 2 == 0:
            # 两个数组之和是偶数
            is_odd = False
        else:
            # 两个数组之和是奇数
            is_odd = True

        idx_of1: int = 0
        idx_of2: int = 0
        i: int = 0

        while i < sz:
            # 取两个数组中较大的那个值，如果一个数组已经取完了
            # 那么返回python3的最大值
            v1: int = nums1[idx_of1] if idx_of1 < len(nums1) else sys.maxsize
            v2: int = nums2[idx_of2] if idx_of2 < len(nums2) else sys.maxsize
            curr: int = 0

            # 根据值的大小决定哪个数组往下移动指针
            if v1 < v2:
                idx_of1 += 1
                curr = v1
            else:
                idx_of2 += 1
                curr = v2

            if is_odd:
                if i == math.floor(sz / 2):
                    return curr
            else:
                if i + 1 == sz / 2:
                    next_v1: int = nums1[idx_of1] if idx_of1 < len(nums1) else sys.maxsize
                    next_v2: int = nums2[idx_of2] if idx_of2 < len(nums2) else sys.maxsize
                    if next_v1 < next_v2:
                        return (curr + next_v1) / 2
                    else:
                        return (curr + next_v2) / 2
            i += 1
        return 0
```