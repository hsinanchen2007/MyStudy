从n位都是0的密码开始，取出最后n-1个数字，然后在末尾增加任意其它数字，用HashSet来记录所有遍历过的密码
```python
class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        total_size = k**n
        res = ["0"]*(n-1)
        visited = set()
        if self.dfs(res,total_size,n,k,visited):
            return "".join(res)
        return ""
    def dfs(self,res,total_size,n,k,visited):
        # print(visited)
        if len(visited) == total_size:
            # print(visited)
            return True
        node = res[len(res)-n+1:]
        for i in range(k):
            node.append(str(i))
            nodestr = "".join(node)
            if nodestr not in visited:
                res.append(str(i))
                visited.add(nodestr)
                if self.dfs(res,total_size,n,k,visited):
                    return True
                visited.remove(nodestr)
                res.pop()
            node.pop()
        return False
```