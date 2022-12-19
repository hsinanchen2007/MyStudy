### 解题思路
一棵二叉树需要满足以下要求：

    1.一个顶点的出度最多为2，入度最多为1;
    
    2.只有一个根节点，即有且只有一个节点的入度为0。

### 代码

```python3
from collections import Counter
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        in_degrees,out_degrees = [0] * n, [0] * n

        for i in range(n):
            if leftChild[i] != -1:
                in_degrees[leftChild[i]] += 1
                out_degrees[i] += 1
            if rightChild[i] != -1:
                in_degrees[rightChild[i]] += 1
                out_degrees[i] += 1
        
        for i in range(n):
            if in_degrees[i] > 1 or out_degrees[i] > 2:
                return False
        d = Counter(in_degrees)
        if 0 not in d or d[0] != 1:
            return False
        return True
```
欢迎关注的我的[github](https://github.com/tcandzq/LeetCode)，查看更多精彩题解。