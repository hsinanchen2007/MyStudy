### 解题思路
DFS+剪枝，用flag记录点的个数，每次遍历判断是否合法，记录访问路径，往前走一步记录flag减一。

### 代码

```python3
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        res = []
        def backtrack(i, path, flag):
            #走到最后，注意因为每次都是后面加个小点，所以复制时不要最后一个点
            if i == n and flag == 0:
                res.append(path[:-1])
                return
            if flag < 0:
                return
            #可以从1位到3位
            for j in range(i, min(n,i + 3)): 
                #如果开头是0,不往后循环              
                if i == j and s[j] == "0":
                    backtrack(j + 1, path + s[j] + ".", flag - 1)
                    break
                #如果在范围内就往前走
                if 0 < int(s[i:j + 1]) <= 255:
                    backtrack(j + 1, path + s[i:j + 1] + ".", flag - 1)

        backtrack(0, "", 4)
        return res
```