### 解题思路
int、str、list 互转
### 代码
```
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        A = [str(x) for x in A]
        int_A = int(''.join(A))
        add = str(int_A + K)
        new_list = [int(x) for x in list(add)]

        return new_list
```
想写成逐位相加，but
写成下面这个样子，就超时。
```
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        A.reverse()
        K = [int(x) for x in list(str(K))]
        K.reverse()

        if len(A) > len(K):
            K += [0] * (len(A) - len(K))
        elif len(K) > len(A):
            A += [0] * (len(K) - len(A))
        
        i = 0

        new_sum = [0] * (len(A)+1)
        while i < len(A):
            print(new_sum)
            new_sum[i+1] = (A[i] + K[i] + new_sum[i]) // 10
            new_sum[i] = (A[i] + K[i]  + new_sum[i]) % 10
            print(A[i], K[i], new_sum[i])
            print(A[i] + K[i] + new_sum[i])
            i += 1
        new_sum.reverse()
        
        if new_sum[0] == 0:
            return new_sum[1:]
        return new_sum
```
