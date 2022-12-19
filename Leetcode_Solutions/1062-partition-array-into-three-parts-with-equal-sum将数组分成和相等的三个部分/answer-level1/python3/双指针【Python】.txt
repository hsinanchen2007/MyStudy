### 思路

**双指针**

```
先整体求和，不能被 3 整除直接返回 False。
再用双指针，分别计算两边的和是否满足等于 sum/3。
注意：题目的意思就是相邻元素相加，而不是任意相加。
```

**时间复杂度:** O(n)
**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum = 0
        for x in A:
            sum += x
        # 和不能被3整除，肯定不符合
        if sum % 3:
            return False
        
        left, right = 0, len(A)-1
        leftSum, rightSum = A[left], A[right]

        # left + 1 < right: 防止将数组只分成两部分，中间部分至少要有一个元素
        while left + 1 < right:
            # 左右都等于sum/3，中间肯定等于sum/3
            if leftSum == sum/3 and rightSum == sum/3:
                return True
            if leftSum != sum/3:
                left += 1
                leftSum += A[left]
            if rightSum != sum/3:
                right -= 1
                rightSum += A[right]
        return False
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1013-Partition-Array-Into-Three-Parts-With-Equal-Sum/1013.py)