```python
def isOneBitCharacter(bits):
    i, N = 0, len(bits)
    while i < N - 1:
        if bits[i] == 0:
            i += 1
        # 处理末尾1, 0这种情况
        elif i + 1 < N - 1 and bits[i + 1] in [0, 1]:
            i += 2
        else:
            return False
    return True

print(isOneBitCharacter([1,0,0]))
print(isOneBitCharacter([1,1,1,0]))
```