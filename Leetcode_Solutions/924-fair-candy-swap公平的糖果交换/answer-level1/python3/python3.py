### 解题思路
注意使用集合表示两个数组，否则会超时

### 代码

```python3
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        dif=(sum(A)-sum(B))//2 
        b=set(B)
        a=set(A)
        for i in a:
            if i-dif in b:
                return [i,i-dif]

            

```