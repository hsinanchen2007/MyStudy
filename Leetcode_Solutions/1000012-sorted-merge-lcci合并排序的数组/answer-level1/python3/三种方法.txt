
## 方法一：直接合并后排序

先将**B**放进数组**A**的尾部，然后直接对整个数组进行排序


```python
class Solution:
    def merge(self,A,m,B,n):
        """
        :param A: List[int]
        :param m: int
        :param B: List[int]
        :param n: int
        :return: None
        """
        A[m:]=B
        
        A.sort()
```

## 方法二：正向双指针

利用数组**A**与**B**已经被排序的性质。将两个数组看作队列，每次从两个数组头部取出比较小的数字放到结果中


```python
class Solution:
    def merge(self,A,m,B,n):
        """
        :param A: List[int]
        :param m: int
        :param B: List[int]
        :param n: int
        :return: None
        """
        res=[]
        i,j=0,0

        while i<m or j<n:
            if i==m:
                res.append(B[j])
                j+=1
            elif j==n:
                res.append(A[i])
                i+=1
            elif A[i]<B[j]:
                res.append(A[i])
                i+=1
            else:
                res.append(B[j])
                j+=1

        A[:]=res
```

## 方法三：逆向双指针

由于**方法二**的空间复杂度较高。**A**的后半部分是空的，可以直接覆盖而不会影响结果。因此指针设置为从后向前遍历，每次取两者之中的较大者放进**A**的最后面


```python
class Solution:
    def merge(self,A,m,B,n):
        """
        :param A: List[int]
        :param m: int
        :param B: List[int]
        :param n: int
        :return: None
        """
        i,j=m-1,n-1
        index=m+n-1

        while i>=0 or j>=0:
            if i==-1:
                A[index]=B[j]
                j-=1
            elif j==-1:
                A[index]=A[i]
                i-=1
            elif A[i]>B[j]:
                A[index]=A[i]
                i-=1
            else:
                A[index]=B[j]
                j-=1
            index-=1
```
