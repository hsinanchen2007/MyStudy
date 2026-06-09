```
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.children = []


class Solution:
    def minimumLengthEncoding(self, words) -> int:
        def get_node_by_val(nodes, val):
            for node in nodes:
                if node.val == val:
                    return node
            return None

        root = TreeNode(None)
        for word in words:
            node = root
            for ch in reversed(word):
                child_node = get_node_by_val(node.children, ch)
                if not child_node:
                    child_node = TreeNode(ch)
                    node.children.append(child_node)
                node = child_node

        count, queue, depth = 0, [root], 1
        while queue:
            for node in queue.copy():
                node = queue.pop(0)
                children = node.children
                if children:
                    queue.extend(children)
                else:
                    count += depth
            depth += 1
        return count

```
