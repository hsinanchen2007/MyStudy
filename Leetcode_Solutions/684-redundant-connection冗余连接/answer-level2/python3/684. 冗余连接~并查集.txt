### 解题思路
之前关于并查集的题解
[朋友圈](https://leetcode-cn.com/problems/friend-circles/solution/547-peng-you-quan-chu-bfsdfswai-huan-you-bing-cha-/)
[由斜杠划分区域](https://leetcode-cn.com/problems/regions-cut-by-slashes/solution/959-you-xie-gang-hua-fen-qu-yu-guan-fang-de-ti-jie/)

下面还是一张图进行解释：
![image.png](https://pic.leetcode-cn.com/99af0f20e4606c329571b5a6014fec53f5599f711662c7f71fb007963e0f4138-image.png)

### 代码

```python3
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        
        cnt = set()
        for i in range(len(edges)):
            for j in range(len(edges[0])):
                cnt.add(edges[i][j])
        N = len(cnt)
        parent = [i+1 for i in range(N)]
        print(parent)
        def find(parent, x):
            if parent[x-1] == x:
                return x
            return find(parent, parent[x-1])
        
        def union(parent, x, y):
            x_root = find(parent, x)
            y_root = find(parent, y)

            if x_root == y_root:
                return [x, y]
            elif x_root != y_root:
                parent[x_root-1] = y_root


        for x, y in edges:
            if union(parent, x, y):
                return union(parent,x, y)
    
```