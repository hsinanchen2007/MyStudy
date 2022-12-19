### 解题思路
与其他实现相比，主要是加了heads和tails

### 代码

```python3
class Node:
    def __init__(self, val):
        self.val = val
        self.right, self.down = None, None
        
class Skiplist:

    def __init__(self):
        self.head = [Node(float('-inf')) for _ in range(16)]
        self.tail = [Node(float('inf')) for _ in range(16)]
        
        for h, t in zip(self.head, self.tail):
            h.right = t
            
        for up, down in zip(self.head, self.head[1:]):
            up.down = down

    def search(self, target: int) -> bool:
        current = self.head[0]
        while current:
            if current.val < target <= current.right.val:
                if current.right.val == target: return True
                current = current.down
            else:
                current = current.right
        return False
        
    def add(self, num: int) -> None:
        stack = []
        current = self.head[0]
        while current:
            if current.val < num <= current.right.val:
                stack.append(current)
                current = current.down
            else:
                current = current.right
        prev = None
        while stack:
            current = stack.pop()
            node = Node(num)
            node.right, current.right = current.right, node
            if prev: node.down = prev
            prev = node
            
            if random.randint(0, 1): break
        

    def erase(self, num: int) -> bool:
        current = self.head[0]
        is_removed = False
        while current:
            if current.val < num <= current.right.val:
                if current.right.val == num: 
                    current.right = current.right.right
                    is_removed = True
                current = current.down
            else:
                current = current.right
        return is_removed
```