```python
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        allowed_dict = collections.defaultdict(list)
        for allow in allowed:
            allowed_dict[allow[:-1]].append(allow[-1])
        record = {}
        def helper(bottom):
            if len(bottom) == 1:return True
            if bottom in record:return record[bottom]
            record[bottom] = False
            if all([bottom[i:i+2] in allowed_dict for i in range(len(bottom)-1)]):
                condidate = [allowed_dict[bottom[i:i+2]] for i in range(len(bottom)-1)]
                for bottom1 in itertools.product(*condidate):
                    bottom1 = ''.join(bottom1)
                    if helper(bottom1):
                        record[bottom] = True
                        break
            return record[bottom]
        res = helper(bottom)
        #print(record)
        return res
```