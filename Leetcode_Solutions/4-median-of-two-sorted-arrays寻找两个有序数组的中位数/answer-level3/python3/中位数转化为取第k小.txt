### 解题思路
把中位数转化为求第k小个数
每次通过二分排除k//2个数

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1, l2 = len(nums1), len(nums2)
        l = l1+l2
        def solve(n1, n2, k): # k代表的是第k小的数
            if not n1: return n2[k-1]
            elif not n2: return n1[k-1]
            if k==1:
                return min(n1[0], n2[0])
            half = k//2
            index1 = index2 = half-1 #要求index要减1
            if len(n1)<half: index1 = len(n1)-1
            elif len(n2)<half: index2 = len(n2)-1
            if n1[index1]<n2[index2]:
                return solve(n1[index1+1:], n2, k-index1-1) #要求长度要index+1
            else:
                return solve(n1, n2[index2+1:], k-index2-1)
        return 0.5*(solve(nums1, nums2, (l+1)//2)+solve(nums1,nums2,(l+2)//2))
        # 对于奇数 第 l1+l2+1//2 或 l1+l2+2//2 个数才是中位数 (第l1+l2+1//2 小)
        # 对于偶数 第 l1+l2+1//2 和 l1+l2+2//2 个数的平均才是中位数 (第 l1+l2+1//2 和 l1+l2+2//2 小)
```