
# 题解
最简单的想法，先合并两个数组再排序。
## 合并加排序

### 复杂度分析
 - 时间复杂度：$O((m+n)log(m+n))$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        nums1[:] = sorted(nums1[:m] + nums2)
```

## 双指针，复制$nums1$

 1. 复制$nums1$为$nums\_copy$，定义指针$l1=0$，$l2=0$
 2. 当$l1<m\ and\ l2<n$时：若$nums\_copy[l1]<nums2[l2]$，则令$nums1[i]=nums\_copy[l1]$,并令$l1+1$。否则令$nums1[i]=nums2[l2]$,并令$l2+1$
 3. 若$l1<m$，说明$nums2$已全部插入完毕，此时将剩下的$nums\_copy$加入$nums1$
 4. 若$l2<n$，说明$nums\_copy$已全部插入完毕，此时将剩下的$nums2$加入$nums1$
### 复杂度分析
 - 时间复杂度：$O(m+n)$。
 - 空间复杂度：$O(m)$

### Python

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        l1=0
        l2=0
        nums_copy=nums1[:m]
        i=0
        while(l1<m and l2<n):
            if(nums_copy[l1]<nums2[l2]):
                nums1[i]=nums_copy[l1]
                l1+=1
            else:
                nums1[i]=nums2[l2]
                l2+=1
            i+=1
        if(l1<m):
            nums1[i:m+n]=nums_copy[l1:m]
        if(l2<n):
            nums1[i:m+n]=nums2[l2:n]
```

## 双指针，从后向前
我们发现$nums1$中尾部存在长度为$n$的零元素区间，可以从后向前插入元素，从而使用$O(1)$空间
 1. 定义$nums1$插入指针$end=m+n-1$，$nums1$指针$end\_1=m-1$，$nums2$指针$end\_2=n-1$
 2. 当$end\_1>=0\ and\ end\_2>=0$时：若$nums1[end\_1]<nums2[end\_2]$，则令$nums1[end]=nums1[end\_1]$,并令$end\_1-1$和$end-1$。否则令$nums1[end]=nums2[end\_2]$,并令$end\_2-1$和$end-1$
 3. 将$nums2$中剩下的元素加入$nums1$。对应两种情况，
 	+ 若nums[2]全部加入，则此时无需修改$nums1$
 	+ 若nums[1]全部加入，则此时将剩下$nums2$加入即可
### 复杂度分析
 - 时间复杂度：$O(m+n)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        end=m+n-1
        end_1=m-1
        end_2=n-1
        while(end_1>=0 and end_2>=0):
            if(nums1[end_1]>=nums2[end_2]):
                nums1[end]=nums1[end_1]
                end_1-=1
                end-=1
            else:
                nums1[end]=nums2[end_2]
                end_2-=1
                end-=1
        nums1[:end_2+1]=nums2[:end_2+1]
```