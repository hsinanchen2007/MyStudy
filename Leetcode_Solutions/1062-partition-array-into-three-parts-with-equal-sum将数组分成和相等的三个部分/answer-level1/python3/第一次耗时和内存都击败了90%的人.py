### 解题思路
1、最开始用的暴力双层循环，用i、j遍历整个列表，然后用切片判断
```
sum(A[0:i+1])==sum(A[i+1:j])==sum(A[j:len(A)])
```
可惜如果A太长的话，直接超时了。

2、因为将A分成了3段，那么每段和都是sum(A)/3，所以用一个循环遍历A，每当和等于sum/3了，就记录一次。最后看这个记录，如果有3次及以上，就证明这个列表可以被分成三段了。

用时128 ms击败92.97%，内存18.8MB击败98.29%
小鸡冻一下。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A) / 3
        temp = 0
        n = 0
        for i in A:
            if temp + i != s:
                temp += i
            else:
                temp = 0
                n += 1
        return n >= 3
```