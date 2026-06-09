```
        begin,end = 0,len(A)-1
        while(end>begin):
            if A[begin]%2==1 and A[end]%2==0:
                A[begin],A[end] = A[end],A[begin]
                begin += 1
                end -= 1
            if A[begin]%2==0:
                begin += 1
            if A[end]%2==1:
                end -= 1
        return A
```
