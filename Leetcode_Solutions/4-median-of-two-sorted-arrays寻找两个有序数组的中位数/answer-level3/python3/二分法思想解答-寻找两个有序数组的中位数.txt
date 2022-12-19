### 解题思路
算法复杂度为 O(log(m + n)) 想到使用二分法
主要思想包括：
要查找第K个元素，分别在两个数组查找K/2个元素arr1[i],arr2[j],小的元素，则是在第K个元素左边，无法成为第k个元素的候选元素，remove掉这些元素（假如个数为s）。继续在我们我们的剩下的元素list里查找第k-s个元素
k为第几个元素，不是下标（下标从0开始），所以只要涉及到由K得到列表元素的，都要额外-1，比如
```
  if j >= len2 - 1:
                    return arr1[k - j-2]  #k-j-2   理解为k-（j+1）-1，
```

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def findKthElement(arr1, arr2, k):
            len1, len2 = len(arr1), len(arr2)
            if k == 1:
                the_min=min(arr1[0], arr2[0])
                return the_min
            i = min(k // 2, len1) - 1
            j = min(k // 2, len2) - 1
            if arr1[i] > arr2[j]:
                if j >= len2 - 1:
                    return arr1[k - j-2]
                else:
                    return findKthElement(arr1, arr2[j + 1:], k - j - 1)
            else:
                if i >= len1 - 1:
                    return arr2[k - i-2]
                else:
                    return findKthElement(arr1[i + 1:], arr2, k - i - 1)

        def find_media_element(arr1, arr2):
            k = len(arr1) + len(arr2)
            mid_left = (k + 1) // 2
            mid_right = (k + 2) // 2
            if len(arr1) == 0:
                return (arr2[mid_left-1] + arr2[mid_right-1]) / 2
            elif len(arr2) == 0:
                return (arr1[mid_left-1] + arr1[mid_right-1]) / 2
            else:
                return (findKthElement(arr1, arr2, mid_left) + findKthElement(arr1, arr2, mid_right)) / 2

        return find_media_element(nums1, nums2)

        
```