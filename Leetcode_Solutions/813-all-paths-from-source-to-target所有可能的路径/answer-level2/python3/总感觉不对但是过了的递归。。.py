```python
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        def helper(i, tmp):
            if not graph[i]:
                res.append(tmp)
            else:
                for item in graph[i]:
                    helper(item, tmp + [item])
        helper(0, [0])
        return res
```

可能是用例都是包含了0->结束的路径  没有在中间断掉  不然这个方法应该是不对的。。
