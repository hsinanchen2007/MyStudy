### 解题思路


  想起之前书中例题，于是尝试：
* 利用pop( )语句，把nums2[ ]列表末尾元素“吹”出来；
* 再利用append() 语句，把列表元素“压”回到nums1[]中。
* 利用list.sort()排序。
* 再判断元素总个数的奇偶情况，分不同情况取中位数即可。



### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:		
        def paixu(nums1,nums2):
            while nums2:
                a = nums2.pop()
                nums1.append(a)
            nums1.sort()
            return nums1
			
        def test_length(nums1):
            len_1 = len(nums1)
            return len_1
		
        def panduanshu(nums1,len_1):
            middle = len_1//2
            if (len_1%2==0):
                result = (nums1[middle] + nums1[middle-1])/2
            else :
                result = nums1[middle]
            return result
        nums1=paixu(nums1,nums2)
        len_1=test_length(nums1)
        result=panduanshu(nums1,len_1)
        return result
```