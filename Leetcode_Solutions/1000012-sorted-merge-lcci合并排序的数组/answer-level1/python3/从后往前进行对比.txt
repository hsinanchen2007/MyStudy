### 解题思路
从有数字的地方开始从后往前对比，大的数字放在A的末端
如果A中数字对比完，B中还有数字没有对比过整体放到A前端
![code.PNG](https://pic.leetcode-cn.com/a863399bb7aff0a139a530a38516b24c2837f14492f334580d17e7cf12c22716-code.PNG)


### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m-1
        j = n-1
        index = m+n-1
        while j>=0 and i>=0:
            if A[i]>=B[j]:
                A[index]=A[i]    
                i = i-1
            elif A[i]<B[j]:
                A[index]=B[j]
                j = j-1
            index -= 1
        if j!=-1:
            A[:j+1]=B[:j+1]
        return A

```