### 解题思路
参考官方思路采用 BFS 的方法，利用队列实现。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/a9e69684f4c8bae5a263fb63360aaea4cc4d42d90d6816f5830f95090c2698b9-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/eb63d67a6889e32bf06c7d3cfd34abca2300e7acfb9900e56ea5febcb1816754-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/5169ca8da0623ba12384ad8b6438e9d5a3cbb1044c44cecf68d1bb219f66bd4b-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/815a2823d7bba5942f613f65ae6b971e8998ff61d4c291bbee5d1f9cdc2981d5-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/e10280f80899abf89e97a561d8606ec184f7fcb04ba34feb178ef72df0d5a764-%E5%B9%BB%E7%81%AF%E7%89%875.JPG)>


### 代码

```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        # 边界条件
        if arr[start] == 0:
            return True

        n = len(arr)
        used = {start} # 已被访问过的结点保存在此集合中
        q = collections.deque([start])  # 初始化队列q
        while q:
            u = q.popleft()

            for v in [u - arr[u],u + arr[u]]:
                if 0 <= v < n and v not in used:
                    if arr[v] == 0:
                        return True
                    used.add(v)
                    q.append(v)
        
        return False
            
```
### 复杂度分析
- 时间复杂度：$O(N)$，遍历了一遍数组。
- 空间复杂度：$O(N)$，使用了集合和队列。