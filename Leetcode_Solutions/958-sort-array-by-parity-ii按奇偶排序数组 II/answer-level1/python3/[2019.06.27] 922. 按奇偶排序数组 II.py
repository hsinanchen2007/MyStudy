双指针解决

```
def sortArrayByParityII(A):
  # i 偶数位置, j 奇数位置
  i = 0
  j = 1
  while(True):
    while i < len(A) and A[i] % 2 == 0: i += 2
    while j < len(A) and A[j] % 2 == 1: j += 2
    if i < len(A) and j < len(A):
      # 交换位置
      A[i], A[j] = A[j], A[i]
      i += 2
      j += 2
    else: 
      return A
```
