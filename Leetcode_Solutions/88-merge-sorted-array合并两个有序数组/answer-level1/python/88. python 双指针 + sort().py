### 解题思路
### 法一:
因为题目要求只能原地修改num1,因此可以使用sort方法()
### 法二:
同样对于解决数组问题，可以使用双指针，一个指针控制nums1[:m]的移动，另一个指针控制nums2的移动。又因为len(nums1[:m])和
len(nums2)不一定相同，所以添加额外条件。
```python
  if i == m or j == n:
        if i == m and j != n:
            nums1[k] = nums2[j]
            j += 1
            continue
        if i != m and j == n:
            nums1[k] = temp[i]
            i += 1
            continue
```
#### **时间复杂度O(m+n)**
#### **空间复杂度O(m)**

### 代码

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # sort()方法实现
        if nums1 is None or nums2 is None:
            return nums1
        nums1[m:m+n] = nums2
        return nums1.sort()
        




        # 双指针,牺牲空间换取时间
        temp = nums1[:m]
        i = 0
        print(temp)
        j = 0
        for k in range(m+n):
            if i == m or j == n:
                if i == m and j != n:
                    nums1[k] = nums2[j]
                    j += 1
                    continue
                if i != m and j == n:
                    nums1[k] = temp[i]
                    i += 1
                    continue
            if temp[i] < nums2[j]:
                nums1[k] = temp[i]
                i += 1
            else:
                nums1[k] = nums2[j]
                j += 1
        return nums1
```