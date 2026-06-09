### 解题思路
最后得到的序列的最小值应该和现在的最小值一样，然后最大值要大于等于最小值+n-1
那么我们可以先排序好，然后从最小值开始扫描，如果有k个重复的话，就给其中k-1个值+1，然后继续，一直到最大值。这样应该是加一操作最少的。

```python
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        i = 0
        j = 0
        times = 0
        while i < len(A): 
            if i == len(A) - 1:
                break
            j = i
            while A[j+1] == A[i]:
                j += 1
                if j == len(A) - 1:
                    break
            #此时A[i] 到 A[j]重复
            if j > i:#有重复值的时候
                for k in range(i+1,j+1):
                    A[k] += 1
                    times += 1
                    # 进行一次move操作
            i += 1
        return times
```
写出来是这样的，但是超时了，毕竟最差的情况下复杂度应该是$O(n^2)$，太可怕了
主要浪费性能的地方就是我每i+1都要重新跑一边这堆重复的数，如果能把这里优化一下就好很多。
实际上，在排序后我们只需要每次加到已经遍历的数的最大值就可以了

```python
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if A == []:
            return 0
        A.sort()
        currentMax = A[0]-1
        times = 0
        for i in range(len(A)):
            if A[i] <= currentMax:
                currentMax += 1
                times += currentMax - A [i]
                A[i] = currentMax
            else:
                currentMax = A[i]
        return times
```
![image.png](https://pic.leetcode-cn.com/d8600c51668c3e4309649faf877d32360680b9fb1da860de943d08e7a7a300e7-file_1584809178896)
