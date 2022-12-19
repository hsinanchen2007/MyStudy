```python
def validMountainArray(A):
    if len(A) < 3:
        return False
    max_index = A.index(max(A))
    if max_index in [0, len(A) - 1]:
        return False
    
    t1 = any([A[i] >= A[i + 1] for i in range(max_index)])
    t2 = any([A[i] <= A[i + 1] for i in range(max_index, len(A) - 1)])
    return not (t1 or t2)

print(validMountainArray([2,1]))
print(validMountainArray([3,5,5]))
print(validMountainArray([0,3,2,1]))
```