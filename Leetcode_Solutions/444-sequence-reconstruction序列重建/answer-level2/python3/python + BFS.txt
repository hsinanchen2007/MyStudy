```python
class Solution:
    def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        if org == [] : return False # special case
        adj = collections.defaultdict(list)
        in_degree = [0] * (len(org) + 1)
        cnt_set = set()
        rest = l = len(org)
        def out_boundary(x, n):
            return x < 1 or x > n
        for seq in seqs:
            if len(seq) == 1: 
                if  out_boundary(seq[0], l): return False
                cnt_set.add(seq[0])
            for i in range(len(seq)):
                a = seq[i]
                cnt_set.add(a)
                if out_boundary(a, l): return False
                if i + 1 < len(seq):
                    b = seq[i + 1]
                    if  out_boundary(b, l): return False
                    cnt_set.add(b)
                    adj[a].append(b)
                    in_degree[b] += 1
        queue = collections.deque()
        if len(cnt_set) != l:  return False
        for i in range(1, len(org) + 1):
            if in_degree[i] == 0:
                queue.append(i)
                rest -= 1
        while queue:
            if len(queue) > 1: return False
            for neibor in adj[queue.popleft()]:
                in_degree[neibor] -= 1
                if in_degree[neibor] == 0:
                    queue.append(neibor)
                    rest -= 1
        return rest == 0
```