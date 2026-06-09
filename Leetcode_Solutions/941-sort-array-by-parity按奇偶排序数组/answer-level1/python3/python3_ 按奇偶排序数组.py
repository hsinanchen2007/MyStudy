```python
def sortArrayByParity(A):
    # i, j设定为头尾索引
    i, j = 0, len(A) - 1
    while i < j:
        # i定位到奇数索引
        if A[i] % 2 == 0:
            i += 1
        # j定位到偶数索引
        elif A[j] % 2 == 1:
            j -= 1
        else:
            # i, j进行交换
            A[i], A[j] = A[j], A[i]
            i += 1
            j -= 1
    return A

print(sortArrayByParity([3,1,2,4]))
```