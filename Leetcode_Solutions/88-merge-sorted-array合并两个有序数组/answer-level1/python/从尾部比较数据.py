从尾部比较数据，两个指针分别指向nums1和nums2的尾部，比较大小。大的往后放。
```python
def merge(nums1, m, nums2, n):
    """
    :type nums1: List[int]
    :type m: int
    :type nums2: List[int]
    :type n: int
    :rtype: None Do not return anything, modify nums1 in-place instead.
    """
    mylen = m+n-1
    m -= 1
    n -= 1
    while m>=0 and n>=0:
        if nums2[n] > nums1[m]:
            nums1[mylen] = nums2[n]
            n -= 1
        else:
            nums1[mylen] = nums1[m]
            m -= 1
        mylen -= 1
    #其中一个数组比较完了的情况：
    if m <0:
        nums1[:mylen+1] = nums2[:n+1]


```