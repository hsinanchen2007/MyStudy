遍历nums2， 在nums1 中找到对应的插入位置，需要注意的是在插入之前需要先pop 出来nums1 末尾的0.

如果i-j == m 说明原来的nums1 里边的值已经遍历完了，后边nums2所有剩余的值都需要插入。


```python
        i = j = 0
        while j != n:
            if nums2[j] <= nums1[i] or i-j>=m:
                nums1.pop()
                nums1.insert(i, nums2[j])
                j = j + 1
            i = i + 1
```
