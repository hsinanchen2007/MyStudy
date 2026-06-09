# 题解
哈哈，这题是我考研的数据结构编程题。最反映算法本质的做法是：三次反转。当然Python的语言特性解决这道题目也有很多办法。不过建议掌握三次反转。

## 三次反转
对于$[1,2,3,4,5,6,7]$，
根据$k=k\%n$，将数组分为两段：

 + 第一段，对应数组下标范围$[0,n-k-1]$段，即$[1,2,3,4]$
 + 第二段，对应数组下标范围$[n-k,n-1]$，即$[5,6,7]$

分为三步：
 1. 反转第一段，[4,3,2,1,5,6,7]
 2. 反转第二段，[4,3,2,1,7,6,5]
 3. 反转整体，[5,6,7,1,2,3,4]

完成！


### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        k=k%n
        def swap(l,r):
            while(l<r):
                nums[l],nums[r]=nums[r],nums[l]
                l=l+1
                r=r-1
        swap(0,n-k-1)
        swap(n-k,n-1)
        swap(0,n-1)
```
**另外一种写法，借助python的切片完成反转。**

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        nums[:] = nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]
```

## 一些pythonic的解法
**切片**
```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n=len(nums)
        k%=n
        nums[:]=nums[n-k:]+nums[:n-k]
```
**插入**
```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        for _ in range(k):
            nums.insert(0, nums.pop())
```
