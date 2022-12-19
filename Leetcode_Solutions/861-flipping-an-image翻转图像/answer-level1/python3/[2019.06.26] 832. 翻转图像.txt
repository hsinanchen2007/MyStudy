
**(1) 自己刚开始想的方法，开始写python 还是很不熟悉**
```
def flipAndInvertImage(A):
  result = []
  for item in A:
    newItem = []
    n = len(item)
    while True:
      print(n)
      if n > 0:
        # 水平翻转 [1, 1, 0] 的结果是 [0, 1, 1], 反转 [0, 1, 1] 的结果是 [1, 0, 0] 
        newItem.append(0 if item[n - 1] == 1 else 1)
        n = n - 1
      else:
        break

    print(newItem)
    result.append(newItem)    

  return result

print(flipAndInvertImage([[1,1,0],[1,0,1],[0,0,0]]))
```

**(2) 别人写的 照着的例子**
这样写更简洁些

```
def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
  # i: 0, data1: [1,1,0]
  for i, data1 in enumerate(A):
    # list[<start>:<stop>:<step>]
    for j, data2 in enumerate(data1[::-1]):
      # 绝对值
      A[i][j] = abs(data2 - 1)
  return A
```
