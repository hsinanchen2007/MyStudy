
-   广度优先遍历，向下更新
-   由题意可知，这个一个无环图，首先使用字典建立图的关系，找到比当前穷的所有的人
-   然后使用广度优先层次遍历，使用父节点更新子节点的更安静的人

```
例如：
richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
quiet = [3,2,5,4,6,1,7,0]
```

![Snipaste_2019-10-17_11-11-59.png](https://pic.leetcode-cn.com/d3c2d118ffb46de014b5611ef781ae971103148d7a58af8e35cbc6fe474b1533-Snipaste_2019-10-17_11-11-59.png)


如上图所示，广度优先，不断的使用更富有的人的安静值更新子节点即可



```python
from collections import defaultdict


class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        graph = defaultdict(list)

        richest = set()

        for rich, rich_man in richer:
            graph[rich].append(rich_man)
            richest.add(rich)
            if rich_man in richest:
                richest.remove(rich_man)

        ans = list(range(len(quiet)))

        temp = richest


        while temp:
            next_temp = set()
            for rich in temp:
                for poor in graph[rich]:
                    if quiet[ans[rich]] < quiet[ans[poor]]:
                        ans[poor] = ans[rich]
                    next_temp.add(poor)
            temp = next_temp

        return ans

```


