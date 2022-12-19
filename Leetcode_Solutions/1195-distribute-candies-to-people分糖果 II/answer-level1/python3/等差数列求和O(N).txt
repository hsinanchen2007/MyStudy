### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        n = num_people
        M = int(((2*candies+1/4)**0.5-1/2)/n)
        residue = candies-(n*(n+1)/2*M+(M-1)*M/2*n*n)
        ans = [0]*num_people
        for i in range(len(ans)):
            ans[i] = int((i+1)*M+M*(M-1)/2*n)
        i = 0
        while residue>0:
            if residue>=(i+1)+M*n:
                ans[i] += int((i+1)+M*n)
                residue -= (i+1)+M*n
            else:ans[i] += int(residue);residue = 0
            i += 1
        return ans
```