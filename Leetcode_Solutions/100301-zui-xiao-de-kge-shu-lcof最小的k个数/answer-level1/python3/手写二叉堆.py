### 解题思路
此处撰写解题思路

### 代码

```python3
class Heap:

    def __init__(self):
        self.heap = []

    def _siftup(self, pos):
        end_pos = len(self.heap)
        start_pos = pos
        new_item = self.heap[pos]
        child_pos = 2 * pos + 1
        while child_pos < end_pos:
            right_pos = child_pos + 1
            if right_pos < end_pos and self.heap[child_pos] >= self.heap[right_pos]:
                child_pos = right_pos
            self.heap[pos] = self.heap[child_pos]
            pos = child_pos
            child_pos = 2 * pos + 1
        self.heap[pos] = new_item
        self._siftdown(start_pos, pos)
        pass

    def _siftdown(self, startpos, pos):
        new_node = self.heap[pos]
        while startpos < pos:
            parent_pos = (pos - 1) >> 1
            parent = self.heap[parent_pos]
            if new_node < parent:
                self.heap[pos] = parent
                pos = parent_pos
                continue
            break
        self.heap[pos] = new_node

        pass

    def push(self, num: int):
        self.heap.append(num)
        self._siftdown(0, len(self.heap) - 1)
        pass

    def pop(self):
        last_node = self.heap.pop()
        if self.heap:
            ret_item = self.heap[0]
            self.heap[0] = last_node
            self._siftup(0)
            return ret_item

        return last_node

        pass


class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        heapq = Heap()
        for item in arr:
            heapq.push(item)
        res = []

        for i in range(k):
            res.append(heapq.pop())
        return res

        pass
```