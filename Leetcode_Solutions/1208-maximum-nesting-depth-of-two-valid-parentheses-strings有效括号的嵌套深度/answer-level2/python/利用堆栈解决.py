### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        from queue import LifoQueue
        if not seq:
            return []
        out_list = []
        last_str = None
        last_val = None
        q = LifoQueue()
        for s in seq:
            if s == "(":
                if not last_str or s != last_str:
                    q.put((s, 0))
                    last_str = s
                    last_val = 0
                elif s == last_str:
                    q.put((s, 1 - last_val))
                    last_val = 1 - last_val
                out_list.append(last_val)
            elif s == ")":
                s, val = q.get()
                last_str = s
                last_val = 1 - val
                out_list.append(val)
            else:
                raise ValueError
        return out_list
```