```python
def isMonotonic(A):
    return all([A[i + 1] <= A[i] for i in range(len(A) - 1)]) or all([A[i + 1] >= A[i] for i in range(len(A) - 1)])
    
print(isMonotonic([1,2,2,3]))
print(isMonotonic([6,5,4,4]))
print(isMonotonic([1,3,2]))
```