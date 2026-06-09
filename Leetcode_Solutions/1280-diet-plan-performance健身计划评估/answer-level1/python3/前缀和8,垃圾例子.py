### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        pre = [0]
        for val in calories:
            pre.append(pre[-1]+val)
        n = len(calories)
        ans = 0
        for i in range(0,n-k+1):
            T = pre[min(i+k,n)]-pre[i]
            if T <lower:
                cur = -1
            elif T>upper:
                cur =1
            else:
                cur = 0
            ans+=cur
        return ans
```