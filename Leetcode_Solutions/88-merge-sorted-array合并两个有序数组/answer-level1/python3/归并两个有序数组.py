### 解题思路
利用归并思想，只不过将两个list的比较改成比较哪个大，同时存储从m+n-1开始存起。
（这样子就能超99.81%，我怎么这么不信呢。。。）
![image.png](https://pic.leetcode-cn.com/80ae421f7fecf4da077b68021183bbf10619d6e456581e5f971e623c3bde0893-image.png)

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i,j=m-1,n-1
        k = m+n-1
        while i>=0 and j>=0:
            if nums1[i]>nums2[j]:
                nums1[k] = nums1[i]
                i-=1
                k-=1
            else:
                nums1[k] = nums2[j]
                j -= 1
                k -= 1
        if i<0:
            nums1[:k+1] = nums2[:j+1]
        
        
```