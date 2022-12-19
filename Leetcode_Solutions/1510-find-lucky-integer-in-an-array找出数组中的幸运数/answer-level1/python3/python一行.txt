### 解题思路
同样的思路，两种写法。

### 代码

```python3
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        # dic = collections.Counter(arr)
        # ans = -1
        
        # for k, v in dic.items():
        #     if k == v and k > ans:
        #         ans = k
        
        # return ans

        return max([k if k == v else -1 for k, v in collections.Counter(arr).items()])


```