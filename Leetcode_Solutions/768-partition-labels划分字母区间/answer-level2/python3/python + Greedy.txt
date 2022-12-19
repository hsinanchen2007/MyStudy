```python
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        # Greedy
        # Time complexity : O(N)
        # Space complexity : O(1)
        # as many parts as possible
        # each charactor only in one part
        end_dic = collections.defaultdict(int) # constant space
        for i, s in enumerate(S):
            end_dic[s] = i
        begin, end = 0, 0
        res = []
        for i in range(len(S)):
            end = max(end, end_dic[S[i]])
            if i == end:
                res.append(end + 1 - begin)
                begin = i + 1
        return res
```