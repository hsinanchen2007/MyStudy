```python
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x: (x[1], x[0]))
        res = []
        def get_insert_index(arr, val, cnt):
            for i, item in enumerate(arr):
                if item[0] >= val: cnt -= 1
                if cnt < 0: return i
            return len(arr)

        for p in people:
            index = get_insert_index(res, p[0], p[1]) 
            res.insert(index, p)
        return res
```