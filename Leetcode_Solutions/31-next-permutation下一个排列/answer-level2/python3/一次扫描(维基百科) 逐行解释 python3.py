# 字典序
给定多个字符，可以按照任意顺序进行排列，所有排列称为全排列。

每一种排列对应一个字符串，如果这些字符串按照字符串大小的顺序进行排序，那么就这种排序是基于字典序的全排列。

比如给定1，2，3，则他们基于字典序的全排列为：
123> 132 > 213 >231 > 312 > 321

# 题解
## 一次扫描（维基百科）
### 算法流程：
 

 1. 定义指针$index1=-1$
 2. 从数组尾到首遍历，找到第一个$nums[i]<nums[i+1]$的索引$index1=i$,若完全逆序，说明不存在下一个较大排列，此时，$index1=-1$，则退出
 3. 从尾到头遍历，找到第一个$nums[j]>nums[index1]$的索引$index2=j$
 4. 将nums[i]和nums[j]交换
 5. 将$(index1+1)-(n-1)$范围内元素逆置。确保得到的是下一个排列。可结合powcai佬的例子去体会。



### 复杂度分析
 - 时间复杂度：$O\left(n\right)$,只扫描了一遍
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(nums,i,j):
            while(i<j):
                nums[i],nums[j]=nums[j],nums[i]
                i=i+1
                j=j-1
            return nums
        n=len(nums)
        index1=-1
        for i in range(n-2,-1,-1):
            if(nums[i]<nums[i+1]):
                index1=i
                break
        if(index1==-1):
            nums=reverse(nums,0,n-1)
            return
        index2=-1
        for j in range(n-1,-1,-1):
            if(nums[j]>nums[index1]):
                index2=j
                break
        nums[index1],nums[index2]=nums[index2],nums[index1]
        nums=reverse(nums,index1+1,n-1)
```