### 解题思路
$dfs(i)$计算的是先手在$stoneValue[i:]$区间内的最高得分。
在某个区间内，先手面临取一堆，取两堆，取三堆的选择，最终取三种选择中的最高分。
状态转移:
$$dfs(i) = max(dfs(i),stoneValue(i:i+j)+sum(stoneValue[i+j:])-dfs(i+j)) ,j=1,2,3$$
注意边界检查及区间变化时的先后手交换，即先手变后手，后手变先手。某个区间内的总和减去其中一人得分即为另一人得分。

### 代码

```python3
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        memo = {}
        reduceValue = [0]* (n+1)
        for i in range(n-1,-1,-1):
            reduceValue[i] = stoneValue[i]+ reduceValue[i+1]
        def dfs(i):
            if i >= n:return 0
            if i in memo:return memo[i]
            ans,cur = -float('inf'),0
            for j in range(i,min(i+3,n)):
                cur += stoneValue[j]
                ans = max(ans,cur + reduceValue[j+1] - dfs(j+1))
            memo[i] = ans
            return ans
        alice = dfs(0)
        Bob = sum(stoneValue) - alice
        if alice == Bob:return 'Tie'
        elif alice > Bob:return 'Alice'
        else:return 'Bob'
```
![image.png](https://pic.leetcode-cn.com/54e3418a82526e0e17024d88f951421f326ee80462cd00d1aebc1335e815f827-image.png)
