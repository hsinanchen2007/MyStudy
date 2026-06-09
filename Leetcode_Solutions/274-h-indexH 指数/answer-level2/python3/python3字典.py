### 解题思路
题目意思难理解
![UC截图20191209135731.png](https://pic.leetcode-cn.com/eb79a796288eb815a4138e89038aa39f03800a47a8382a9a07e9496c5d2451e3-UC%E6%88%AA%E5%9B%BE20191209135731.png)


### 代码

```python3
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        if not citations:
            return 0
        d = {}
        n = len(citations)
        citations = sorted(citations)
        if citations[0] >= n:
            return n
        for i in range(1,n):
            d[n - i] = citations[i]
        # print(d)
        ans = -float('inf')
        for item in d.keys():
            if d[item] >= item:
                ans = max(ans,item)
        if ans < 0:
            return 0
        return ans
```