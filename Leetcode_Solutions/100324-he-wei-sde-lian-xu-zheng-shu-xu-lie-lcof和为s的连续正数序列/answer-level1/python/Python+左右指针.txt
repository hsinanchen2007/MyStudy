### 解题思路
分析：
1. 返回的序列是连续正整数；
2. 返回所有序列和为target的可能；
故此，可以该数组的边界可知，即为：target//2 + 1

思路：
1. 创建一个连续的正整数数组并赋值，数组大小为 target//2+1，a[i] = i+1；
2. 设置左、右指针（即子序列的首尾位置），求和判断所有可能的序列；
3. 保存所有序列和为 target 的序列。

### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        left, right, size = 0, 0, target//2+1
        res =[]
        array = []
        sum_ = 0
        for i in range(size):
            array.append(i+1)
        
        while left<size and right<size:
            if sum_ < target:
                sum_ += array[right]
                right += 1
            if sum_ > target:
                sum_ -= array[left]
                left += 1
            if sum_ == target:
                res.append(array[left:right])
                sum_ -= array[left]
                left += 1
        return res  

```