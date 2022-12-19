### 解题思路
参考一位老大C++的思路，动态规划，算法时间复杂度为O（n）,空间复杂度为O（1）
依次比较前后两个元素，有三种情况：
    1.如果A[i] == A[i+1]，那么prelen重置为1
    2.如果该两元素比较符号与preop相反，那么prelen += 1
    3.如果该两元素比较符号与preop相同，那么这两个元素成对，设置prelen = 2
### 代码

```python3
class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        l = len(A)
        if l <= 1: return l
        prelen = 1; preop = '='; ans = 1
        for i in range(l - 1):
            if (A[i] > A[i+1] and preop == '<') or (A[i] < A[i+1] and preop == '>'):
                prelen += 1
            elif A[i] == A[i+1]:
                prelen = 1
            else:
                prelen = 2
            preop = '=' if A[i] == A[i+1] else '>' if A[i] > A[i+1] else '<'
            ans = max(ans, prelen)
        return ans
        
                
                

                


```