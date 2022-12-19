1. 考虑到负数平方后是需要重新排序, 并且负数数组是个倒序排序. 直接使用内置的方法

```
def sortedSquares(A):
  for i, d in enumerate(A):
    A[i] = d ** 2
  return sorted (A)
```

2. 可优化的点是, 排序算法次
第一次即可区分两个分组 [正数平方的正序组] [负数平方的倒序组]
针对两个组可以进行合并算法的最后一步
但是这样写并没有很优秀....
```
class Solution(object):
    def sortedSquares(self, A):
        separate = 0
        for i, d in enumerate(A):
          if d < 0: 
            separate = i
          A[i] = d ** 2
        
            
        positive = A[separate + 1: len(A)]
        negative = A[0: separate + 1]
        print(positive, negative)
        i = 0
        j = len(negative) - 1
        List = []

        while(i < len(positive) and j > -1):
          x = positive[i]
          y = negative[j]
          if x > y: 
            List.append(y)
            j = j - 1
          else: 
            List.append(x)
            i = i + 1
        List += positive[i:]
        List += sorted(negative[0:j+1])
        return List

```
