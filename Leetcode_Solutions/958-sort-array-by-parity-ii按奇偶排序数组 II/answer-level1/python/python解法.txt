### 解题思路
先把基数偶数分别分到新建的两个列表里，再将他们填入A列表
执行用时 :252 ms, 在所有 Python 提交中击败了19.14%的用户
内存消耗 :13.8 MB, 在所有 Python 提交中击败了78.00%的用户
### 代码

```python
class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        a=list()
        b=list()
        for i in A:
            if i%2==0:
                a.append(i)
            else:
                b.append(i)
        j=0
        for i in range(0,len(A),2):
            A[i]=a[j]
            j+=1
        k=0
        for i in range(1,len(A),2):
            A[i]=b[k]
            k+=1
        return A


```