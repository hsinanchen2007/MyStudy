```
class Solution:
    def terminateprocess(self, pid, ppid, kill):
        """
           能宽搜就用宽搜, 好理解, 并且迭代的效率也高
        """
        from collections import defaultdict
        
        tree_structure = defaultdict(list)
        for chird, par in zip(pid, ppid):
            tree_structure[par].append(chird)
        
        stacks = [kill]
        ans = []

        while stacks:
            curr_node = stacks.pop(0)
            ans.append(curr_node)
            
            next_nodes = tree_structure.get(curr_node)

            if next_nodes is not None:
                for x in next_nodes:
                    stacks.append(x)
        
        return ans
```
