```
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        out_degree = {}
        in_degree = {}
        if not trust:
            return N

        for i in trust:
            cnt_out = out_degree.get(i[0])
            if cnt_out is None:
                out_degree[i[0]] = 1
            else:
                out_degree[i[0]] += 1
            cnt_in = in_degree.get(i[1])
            if cnt_in is None:
                in_degree[i[1]] = 1
            else:
                in_degree[i[1]] += 1
        for key in in_degree.keys():
            if in_degree[key] == N - 1 and out_degree.get(key) is None:
                return key
        return -1

```