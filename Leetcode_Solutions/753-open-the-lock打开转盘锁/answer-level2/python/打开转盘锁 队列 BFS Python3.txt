### 解题思路
执行用时 :676 ms, 在所有 Python3 提交中击败了84.68%的用户
内存消耗 :14.8 MB, 在所有 Python3 提交中击败了5.00%的用户

注意：
1. 每次旋转都只能旋转**一个**拨轮的**一位**数字
2. 深度如何计算，入栈的是：(数字字符串，深度)

### 代码

```python3
class Solution:

    def get_neighbours(self, nodes):
        for i in range(len(nodes)):
            num = int(nodes[i])
            for j in [1, -1]:
                node = str((num + j) % 10)
                yield nodes[0: i] + node + nodes[i + 1:]

    def openLock(self, deadends: List[str], target: str) -> int:
        if "0000" in deadends:
            return -1
        deadends = set(deadends)
        queue = deque()
        queue.append(("0000", 0))
        marked = set("0000")

        while queue:
            node, depth = queue.popleft()
            # print(node, depth)
            for item in self.get_neighbours(node):
                if item == target:
                    return depth + 1
                if item not in marked and item not in deadends:
                    queue.append((item, depth + 1))
                marked.add(item)
        return -1
```