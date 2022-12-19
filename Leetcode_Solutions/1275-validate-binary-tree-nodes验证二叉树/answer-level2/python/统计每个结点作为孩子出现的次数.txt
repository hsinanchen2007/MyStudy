### 解题思路
1. 有且只有一个根结点，它没有父结点。它不作为任何结点的孩子出现。
2. 其他所有的结点，都只有一个父结点，只作为一个结点的孩子出现。
3. 所以我们去遍历`leftChild`和`righrChild`两个list，统计每个结点作为孩子出现的次数。并验证是不是除了一个结点的次数是0外，其他结点都是1。

### 代码

```python3
class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        visited = [0] * n
        for i in range(n):
            if leftChild[i] != -1:
                visited[leftChild[i]] += 1
            if rightChild[i] != -1:
                visited[rightChild[i]] += 1
        return visited.count(0) == 1 and visited.count(1) == n-1
```