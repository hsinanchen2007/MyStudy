
奇数
nums1=[1,3]
nums2=[2]
nums3=[1,3,2]
nums3.sort=[1,2,3]
偶数情况
nums1=[1,3]
nums2=[2,4]
nums3=[1,3,2,4]
nums3.sort=[1,2,3,4]

 1. 列表1 和 2 进行合并，得到列表nums3=[1,3,2]
 2. 将 nums3 排序
 3. 分两种情况，两个列表的个数和为奇数 直接返回  l1+l2//2 的位置数值，因为python列表是从0开始计算的 因此 //2的值刚好是中间
 4. 如果两列表个数为偶数那么 将 l1+l2//2 和它前面的一位数 的和除2 即可。

```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums3=nums1+nums2
        nums3.sort()
        l1=len(nums1)
        l2=len(nums2)
        if (l1+l2)%2:
            return nums3[(l1+l2)//2]
        else:
            return (nums3[(l1+l2)//2]+nums3[(l1+l2)//2-1])/2
```
