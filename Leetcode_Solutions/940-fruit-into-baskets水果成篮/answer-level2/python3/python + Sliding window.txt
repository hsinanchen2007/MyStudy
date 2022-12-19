```python
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        # two baskets
        # each baskets only carry one type of fruit
        # sliding window(2)=> the maximum of window sum values

    
        left, cnt, res = 0, 0, 0
        dic = collections.defaultdict(int)
    
        for t in tree:
            dic[t] += 1
            cnt += 1
            while len(dic) > 2:
                dic[tree[left]] -= 1
                if dic[tree[left]] == 0: del dic[tree[left]]
                cnt -= 1
                left += 1
            res = max(res, cnt)
        return res
```