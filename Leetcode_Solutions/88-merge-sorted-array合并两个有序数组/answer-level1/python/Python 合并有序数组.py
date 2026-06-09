### 解题思路
两个有序数组，小的数组合并到大的数组上，从头遍历要多次移动元素，不太可取，固整体采用三指针从尾遍历
i 为nums1数组的尾指针（即m-1）
j 为nums2数组的尾指针（即n-1）
k 为整个nums1数组的尾指针

从尾遍历需要分下面的情况：
1.i<0,即nums1的数组从尾遍历完成，则只需将nums2数组内剩余的元素依次放进nums1数组内
2.j<0,即nums2的数组从尾遍历完成，则整个工作便已完成
3.剩下两种情况即最基本的nums1和nums2的元素进行比较，先大就先放进nums1数组的k处

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
        i = m - 1
        j = n - 1
        k = m + n - 1
        while(j >= 0 or i >= 0):
            if i < 0:
                nums1[k] = nums2[j]
                j -= 1
            elif j < 0:
                break
            elif nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        return nums1
                

```