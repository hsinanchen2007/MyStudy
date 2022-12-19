```python      
        A[:] = A[:m] + B
        A.sort()
```     

```python
        copy = A[:m]
        a, b, i = 0, 0, 0
        while a < m and b < n:
            if copy[a] < B[b]:
                A[i] = copy[a]
                a += 1
            else:
                A[i] = B[b]
                b += 1
            i += 1
        if a<m:
            A[a+n:] = copy[a:]
        if b<n:
            A[b+m:] = B[b:]
```