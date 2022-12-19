```
class Solution(object):
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        dismap = {}
        for i in dislikes:
            dismap.setdefault(i[0], []).append(i[1])
            dismap.setdefault(i[1], []).append(i[0])
                
        while dismap:
            group = {}
            delnode = []
            for i in dismap:
                if not group:
                    group[i] = True
                if i not in group:
                    continue
                iv = group[i]
                for j in dismap[i]:
                    if j in group:
                        if group[j] == iv:
                            return False
                    else:
                        group[j] = not iv
                delnode.append(i)
            for i in delnode:
                del dismap[i]
                
        return True
```
