### 解题思路
前缀和

### 代码

```python3
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        res = [0]
        ans = 0
        for i in range(len(arr)):
            res.append(res[-1] + arr[i])
        # print(res)
        for i in range(len(res) - k):
            b = res[i + k]
            a = res[i]
            if (b - a) / k >= threshold:
                ans += 1
        return ans
```