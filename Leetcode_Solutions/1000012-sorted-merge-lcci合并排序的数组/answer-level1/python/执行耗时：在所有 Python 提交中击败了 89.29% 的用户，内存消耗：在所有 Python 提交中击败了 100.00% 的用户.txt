### 解题思路
本题解题方法使用了双子针的形式，倒序插入数组。最后还要考虑A元素全部move完后，剩余B元素的copy动作

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """

        while m >= 1 and n >= 1:
            index = m+n-1
            if B[n-1] >= A[m-1]:
                n -=1
                A[index] = B[n]
            else:
                m -=1
                A[index] = A[m]

        if m == 0:
            for i in range(n):
                A[i] = B[i]

        

        


```