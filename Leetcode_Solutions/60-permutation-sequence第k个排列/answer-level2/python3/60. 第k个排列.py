### 解题思路
看到排列组合题，二话不说上回溯！不过像这种有要求的排列，需要考虑到剪枝，由于一个叶子结点就代表一个排列情况，所以为了更快找到第k个，可以考虑按顺序减掉不符合要求的会生成那些叶子的子树。

### 代码

```python3
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def numOfLeaf(visited):
            num = 0
            for i in range(n):
                if not visited[i]:
                    num += 1
            res = 1
            for i in range(1, num + 1):
                res *= i
            return res

        def backtrack(combination):
            nonlocal k,res
            if len(combination) == n:
                k -= 1
                if k==0:
                    res = combination
                return
            for i in range(n):
                if visited[i]:
                    continue
                visited[i] = True
                # 剪枝
                num_leaf = numOfLeaf(visited)
                if num_leaf >= k:
                    backtrack(combination + arr[i])
                else:
                    k -= num_leaf
                if k==0:
                    return
                visited[i] = False

        res = ""
        arr = ""
        visited = [False] * n
        for i in range(1, n + 1):
            arr += str(i)
        backtrack("")
        return res
```