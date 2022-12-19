### 解题思路
1. 思路最简单，也是最常规的方法，循环分配，一遍提交了
2. 看了官方题解，虽然简单暴力，但简单方法还是有值得学习的地方：
    - ans[i % num_people] += min(i + 1, candies)
3. 更高阶解法 等差数列求和 公式推导 -- 数学知识推导
### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        if num_people < 1:
            return None
        ans = [0 for i in range(num_people)]
        if candies < 1:
            return ans
        cnt = 0
        i = 0
        while i < num_people:
            cnt += 1
            if cnt <= candies:
                ans[i] += cnt
                candies -= cnt
            else:
                ans[i] += candies
                break
            i += 1
            if i == num_people:
                i = 0
        return ans 
```