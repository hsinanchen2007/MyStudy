### 解题思路
双指针，从最大的开始，依次放到数组最后面

### 代码
```

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i=m-1
        j=n-1
        tail=m+n-1
        while i>=0 and j>=0:
            if nums1[i]<nums2[j]:
                nums1[tail]=nums2[j]
                j-=1
            else:
                nums1[tail]=nums1[i]
                i-=1
            tail-=1
        nums1[:j+1]=nums2[:j+1]
```


