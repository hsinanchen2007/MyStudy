```python
def fib(N):
    if N in [0, 1]:
        return N
    a, b = 0, 1
    while N > 1:
        a, b = b, a + b
        N -= 1
    return b

print(fib(3))
```