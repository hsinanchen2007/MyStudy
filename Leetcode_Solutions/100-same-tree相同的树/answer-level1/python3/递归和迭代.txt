
## 思路:

思路一:递归

思路二:迭代

直接看代码!

## 代码:

思路一:递归

```python [1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q: return True
        if p and q and p.val == q.val :
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)     
        return False
```



```java [1]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p != null && q != null && p.val == q.val) return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        else return false;
    }
}
```



思路二:

```python [2]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        stack = [(q, p)]
        while stack:
            a, b = stack.pop()
            if not a and not b:
                continue
            if a and b and a.val == b.val:
                stack.append((a.left, b.left))
                stack.append((a.right,b.right))
            else:
                return False
        return True
```



```java [2]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Deque<TreeNode> stack1 = new LinkedList<>();
        Deque<TreeNode> stack2 = new LinkedList<>();
        stack1.push(p);
        stack2.push(q);
        while (!stack1.isEmpty() && !stack2.isEmpty()) {
            TreeNode a = stack1.pop();
            TreeNode b = stack2.pop();
            if (a == null && b == null) continue;
            if (a != null && b != null && a.val == b.val) {
                stack1.push(a.left);
                stack1.push(a.right);
                stack2.push(b.left);
                stack2.push(b.right);
            } else return false;
        }
        return stack1.isEmpty() && stack2.isEmpty();
    }
}
```

