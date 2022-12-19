### 代码

```python3

class Solution:
    def totalFruit(self, tree: List[int]) -> int: 
        bucket = []
        tree_nums = len(tree)
        cnt = 0
        pos0 = 0
        pos1 = 0
        result = []
        for i in range(tree_nums):
            if tree[i] not in bucket:
                bucket.append(tree[i])
                if len(bucket) > 2:
                    result.append(cnt)
                    if pos1 < pos0:
                        bucket.pop(1)
                        cnt = (i - pos1 - 1)
                    else:
                        bucket.pop(0)
                        cnt = (i - pos0 - 1)
                        pos0 = pos1
            if tree[i] == bucket[0]:
                pos0 = i
            if len(bucket) == 2 and tree[i] == bucket[1]:
                pos1 = i
            cnt += 1

        result.append(cnt)
        return max(result)
```