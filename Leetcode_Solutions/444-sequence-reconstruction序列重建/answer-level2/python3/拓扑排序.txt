```
class Solution:
    def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        from collections import defaultdict
        indegrees = defaultdict(int)
        directed_graph = defaultdict(list)
        seq_set = set()

        for seq in seqs:
            seq_set = seq_set | set(seq)
            for i in range(1, len(seq)):
                directed_graph[seq[i-1]].append(seq[i])
                indegrees[seq[i]] += 1
        if len(seq_set) == 0:
            return False
        if len(set(org) & seq_set) != len(seq_set):
            return False
        queue = []
        for ele in org:
            if indegrees.get(ele) is None:
                queue.append(ele)
        
        if len(queue) == 0 or len(queue) > 1:
            return False
        
        ans = []
        while queue:
            new_queue = []

            for cur in queue:
                ans.append(cur)
                # 将其后续所有节点的入度都减一
                next_nodes = directed_graph.get(cur)
                if next_nodes is not None:
                    for node in next_nodes:
                        indegrees[node] -= 1

                        if indegrees[node] == 0:
                            new_queue.append(node)
            
            if len(new_queue) > 1:
                return False
            
            queue = new_queue
        
        if len(set(org) & set(ans)) == len(org):
            return True
        
        return False
```
