(1) 暴力求解法
这个是我刚开始想到的，但是时间复杂度并不好
```
def addToArrayForm(A, K):
  Str = ''
  for d in A: Str += str(d)
  # 455
  Str = str(int(Str) + K)
  A = list(Str)
  for i in range(len(A)): A[i] = int(A[i])
  return A
  print(addToArrayForm([2,7,4], 181))
```
(2) 看到官方解题方法
余数和除数方法
```
def addToArrayForm(A, K):
  # A的最后一位加上K, [2,7,185]
  A[-1] += K
  carry = 0
  for i in xrange(len(A) - 1, -1, -1):
    # divmod(a,b) -> (carry除数,下一个位置为余数)
    carry, A[i] = divmod(A[i], 10)
    if i: A[i - 1] += carry

  print(carry)
  if carry:
    A = map(int, str(carry)) + A
  return A
```
