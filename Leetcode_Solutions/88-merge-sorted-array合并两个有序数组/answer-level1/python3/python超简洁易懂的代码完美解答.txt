### 解题思路
这里还是使用双指针的方法解决，这里有个技巧是从尾向首遍历。
一个指针遍历nums1，另一个指针遍历nums2，每次判断最末尾的数的大小，将较大的数填充到nums1的尾部。
直至某个指针遍历完成为止，并将剩余的数组内容填充到nums1中。
注意点：
nums1[:index2+1]=nums2[:index2+1]
这里使用nums1[:index2+1]而非nums1[:indexMerge+1]的原因：在特殊情况下会nums1[:indexMerge+1]会报错
例如输入：
nums1=[0], m=0, nums2=[1], n=1
![image.png](https://pic.leetcode-cn.com/64c122275062eff5da1fd4f1bb657c63a10de35a82491ef33bfc51a3e823f7ac-image.png)

### 代码

```python
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        index1, index2 = m-1, n-1
        indexMerge = m+n-1
        while index1>=0 and index2>=0:
            if nums1[index1]>nums2[index2]:
                nums1[indexMerge]=nums1[index1]
                index1 -= 1
            else:
                nums1[indexMerge]=nums2[index2]
                index2 -= 1
            indexMerge -=1
        nums1[:index2+1]=nums2[:index2+1]
```