### 解题思路
官方题解思路

### 代码

```python3
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        if n==1:
            return None
        elif k==1:
            return [i for i in range(1,n+1)]
        else:
            front_part=[_ for _ in range(1,n-k)]
            i,j=max(n-k,1),n
            while i<=j:
                if i==j:                        
                    front_part.append(i)
                else:
                    front_part.append(i)
                    front_part.append(j)
                i+=1
                j-=1
            return front_part
```