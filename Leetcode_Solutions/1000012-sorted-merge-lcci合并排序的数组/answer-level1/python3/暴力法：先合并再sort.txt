### 解题思路
暴力法：先合并再sort


### 代码

```python3
'''
题目目标：AB两个数组已排序，把B合并到A
解题思路：
比较A的最大和B的最小
重叠的，多余大的

'''
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        if n > 0:
            for i in range(n):A[i+m] = B[i]
            A.sort()
        

       
        



```