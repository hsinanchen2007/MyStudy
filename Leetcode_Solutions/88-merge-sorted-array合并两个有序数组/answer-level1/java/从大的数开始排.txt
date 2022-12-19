
## 思路:

一句话解释:用大的值填坑

详细解释:

我们比较两个数组的最大值依次填入!

这道题,可以用极端情况考虑,

例如:

`nums1 = [4,5,6,0,0,0],nums2 = [1,2,3]`

`nums1 = [1,2,3,0,0,0],nums2 = [4,5,6]`

就可以很容易理解代码了!

## 代码:



```python [1]
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = m - 1
        j = n - 1
        k = m + n - 1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        while j >= 0:
            nums1[k] = nums2[j]
            k -= 1
            j -= 1
```


```java [1]
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--]:nums2[j--];
        while (j >= 0) nums1[k--] = nums2[j--];   
    }
}
```

