#### 方法一：迭代

由于递归实现 `N` 叉树的前序遍历较为简单，因此我们只讲解如何使用迭代的方法得到 `N` 叉树的前序遍历。

我们使用一个栈来帮助我们得到前序遍历，需要保证栈顶的节点就是我们当前遍历到的节点。我们首先把根节点入栈，因为根节点是前序遍历中的第一个节点。随后每次我们从栈顶取出一个节点 `u`，它是我们当前遍历到的节点，并把 `u` 的所有子节点逆序推入栈中。例如 `u` 的子节点从左到右为 `v1, v2, v3`，那么推入栈的顺序应当为 `v3, v2, v1`，这样就保证了下一个遍历到的节点（即 `u` 的第一个子节点 `v1`）出现在栈顶的位置。

```Python [sol1]
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is None:
            return []
        
        stack, output = [root, ], []            
        while stack:
            root = stack.pop()
            output.append(root.val)
            stack.extend(root.children[::-1])
                
        return output
```

```Java [sol1]
class Solution {
    public List<Integer> preorder(Node root) {
        LinkedList<Node> stack = new LinkedList<>();
        LinkedList<Integer> output = new LinkedList<>();
        if (root == null) {
            return output;
        }

        stack.add(root);
        while (!stack.isEmpty()) {
            Node node = stack.pollLast();
            output.add(node.val);
            Collections.reverse(node.children);
            for (Node item : node.children) {
                stack.add(item);
            }
        }
        return output;
    }
}
```

**复杂度分析**

* 时间复杂度：时间复杂度：$O(M)$，其中 $M$ 是 `N` 叉树中的节点个数。每个节点只会入栈和出栈各一次。

* 空间复杂度：$O(M)$。在最坏的情况下，这棵 `N` 叉树只有 `2` 层，所有第 `2` 层的节点都是根节点的孩子。将根节点推出栈后，需要将这些节点都放入栈，共有 $M - 1$ 个节点，因此栈的大小为 $O(M)$。