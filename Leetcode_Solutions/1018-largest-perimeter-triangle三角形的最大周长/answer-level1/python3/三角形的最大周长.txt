### 解题思路
最大周长的组合，肯定是可能组成三角形的所有三角形里包含边长最长的。先给列表排序，从最长的开始拼三角形。
三角形的两个条件：
1. 任意两边之和大于第三边；
2. 任意两边之差小于第三边；

### 代码

```python3
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A = sorted(A)
        index = len(A) - 1
       
        while index-2 >= 0:
            if A[index-1] + A[index-2] <= A[index]:  # 两边之和大于第三边：最小的两条边的和小于第三边满足条件即可
                index -= 1
                continue
            if (A[index] - A[index-1]) < A[index-2] and (A[index -1] - A[index-2]) < A[index] and (A[index] - A[index-2]) < A[index-1]: # 两边之差小于第三边：需要两两组合
                return A[index-2] + A[index-1] + A[index]
        return 0
                
```