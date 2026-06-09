```
class Solution(object):
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
        n = len(org)
        in_degree = [-1] * (n + 1)
        out_degree = [set() for _ in xrange(n + 1)]
        for seq in seqs:
            for i in xrange(len(seq)):
                if seq[i] > n or seq[i] <= 0:
                    return False
                if i == 0 or seq[i] not in out_degree[seq[i - 1]]:
                    if in_degree[seq[i]] == -1:
                        in_degree[seq[i]] = 0
                    if i > 0:
                        in_degree[seq[i]] += 1
                        out_degree[seq[i - 1]].add(seq[i])

        node = -1
        for i in xrange(1, n + 1):
            if in_degree[i] == 0:
                if node == -1:
                    node = i
                else:
                    return False

        for n in org:
            if n != node:
                return False
            
            node = -1
            for next_node in out_degree[n]:
                in_degree[next_node] -= 1
                if in_degree[next_node] == 0:
                    if node == -1:
                        node = next_node
                    else:
                        return False

        return node == -1
```
