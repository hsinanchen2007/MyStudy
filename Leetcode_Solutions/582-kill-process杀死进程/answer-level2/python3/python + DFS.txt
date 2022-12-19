```python
class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        #      0
        #     / 
        #    3
        #   / \
        #  1   5
        #       \
        #       10
        tree = collections.defaultdict(list)
        for p, pp in zip(pid, ppid):
            tree[pp].append(p)
        res = []
        def traverse_process(pid):
            res.append(pid)
            for val in tree[pid]:
                traverse_process(val)
        traverse_process(kill)
        return res
```