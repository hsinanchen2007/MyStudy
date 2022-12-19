### 解题思路
base=2**n
2**n+1~2**(n+1)-1之间的数等于减去base后的数的比特位总数+1

### 代码

```python3
class Solution:
    def countBits(self, num: int) -> List[int]:
        """
        base=2**n
        2**n+1~2**(n+1)-1之间的数等于减去base后的数的比特位总数+1
        """
        if num==0:
            return [0]
        if num==1:
            return [0,1]
        res = [0,1]
        base = 1
        for i in range(2,num+1):
            if i==base*2:
                res.append(1)
                base=i
                continue
            res.append(1+res[i-base])
        return res
        
```