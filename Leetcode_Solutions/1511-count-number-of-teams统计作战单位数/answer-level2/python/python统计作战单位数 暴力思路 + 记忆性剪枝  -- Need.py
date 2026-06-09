### 解题思路
1. 理解题意：大白话
    - 在数组中，找上升的序列（非子数组）或下降的序列，3个元素
    - 数组的item值唯一，处理边界

2. 解题思路：
    - 很容易想到的是暴力求解发，O(N*N*N)
    - 尝试着思考有没有DP动态规划的思路，暂时没有想通
    - 再次回头思考暴力求解，想到了记忆化剪枝策略：再处理第二个数j时，比rating[j] 大的数或小的数，做一下记录

3. 也许是提交的人比较少？
![image.png](https://pic.leetcode-cn.com/761a22bffbe76e434a63c3e3288b9a69a952432fa59bf6b4f7d85d91a830782d-image.png)

### 代码

```python
class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        n = len(rating)
        if n < 3:
            return 0
        dp = dict()
        res = 0
        for i in range(n):
            val = dp.get(rating[i], 0)
            if val != 0 and val < 2:
                continue 
            for j in range(i+1,n): 
                if rating[i] >= rating[j]:
                    continue
                val = dp.get(rating[j], 0)
                if val != 0:
                    if val >= 1:
                        res += val
                    continue
                for k in range(j+1, n):
                    if rating[j] < rating[k]:
                        dp[rating[j]] = dp.get(rating[j], 0) + 1
                        res += 1
        dp.clear()
        for i in range(n):
            val = dp.get(rating[i], 0)
            if val != 0 and val < 2:
                continue 
            for j in range(i+1,n):
                if rating[i] <= rating[j]:
                    continue
                val = dp.get(rating[j], 0)
                if val != 0:
                    if val >= 1:
                        res += val
                    continue 
                for k in range(j+1, n):
                    if rating[j] > rating[k]:
                        dp[rating[j]] = dp.get(rating[j], 0) + 1
                        res += 1
        

        return res 
```

代码二：思路更清晰，动态规划的意思：
```
// java 
public int numTeams(int[] rating) {
        int n = rating.length;
        int res = 0;
        
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        Arrays.fill(dp1, 1);
        Arrays.fill(dp2, 1);
        
        for(int i = 1; i < n; i++) {
            int a = 1;
            int b = 1;
            for(int j = 0; j < i; j++) {
                if (rating[i] > rating[j]) {
                    a++;
                    res += (dp1[j] - 1);
                } else {
                    b++;
                    res += (dp2[j] - 1);
                }
            }
            
            dp1[i] = a;
            dp2[i] = b;
        }
        
        return res;
    }
```