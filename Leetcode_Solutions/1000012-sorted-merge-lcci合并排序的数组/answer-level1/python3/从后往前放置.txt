### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        #从后往前放置

        a=m-1
        b=n-1
        last=m+n-1
        while a>=0 or b>=0:            
            while a>=0 or b>=0 :
                print(a,b)
                if a>=0 and b>=0 and (A[a]>=B[b]):
                    A[last]=A[a]
                    a-=1
                    last-=1
                if  a>=0 and b>=0 and (A[a]<B[b]):
                    A[last]=B[b]
                    b-=1
                    last-=1
                if a==-1 and b>=0:                    
                    A[last]=B[b]
                    b-=1
                    last-=1
                    print(A)
                if b==-1 and a>=0:
                    A[last]=A[a]
                    a-=1
                    last-=1            
        print(A)
```