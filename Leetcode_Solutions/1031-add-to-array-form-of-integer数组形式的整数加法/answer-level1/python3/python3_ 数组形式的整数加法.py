```python
def addToArrayForm(A, K):
    A = list(reversed(A))
    K = list(reversed(list(str(K))))
    k, i, r = 0, 0, []
    while i < len(A) and i < len(K):
        v = A[i] + int(K[i]) + k
        k = 1 if v >= 10 else 0
        v %= 10
        r.append(v)
        i += 1
    while i < len(A):
        v = A[i] + k
        k = 1 if v >= 10 else 0
        v %= 10
        r.append(v)
        i += 1
    while i < len(K):
        v = int(K[i]) + k
        k = 1 if v >= 10 else 0
        v %= 10
        r.append(v)
        i += 1
    if k == 1:
        r.append(1)
    return list(reversed(r))

print(addToArrayForm([1,2,0,0], 34))
```