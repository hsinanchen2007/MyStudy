## 思路:

这道题和 上一题 [100. 相同的树](https://leetcode-cn.com/problems/same-tree/)是一样的

我们只要比较`root`左右树是否对称(和是否相同的树类似)就行了

思路一:递归

思路二:迭代

思路三:层次遍历

## 代码:

思路一:

```python [1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        def Tree(p, q):
            if not p and not q: return True
            if p and q and p.val == q.val :
                return Tree(p.left, q.right) and Tree(p.right, q.left)     
            return False
        return Tree(root.left, root.right)
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return Tree(root.left, root.right);

    }

    public boolean Tree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p != null && q != null && p.val == q.val) return Tree(p.left, q.right) && Tree(p.right, q.left);
        else return false;
    }
}
```


```python [2]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        def Tree(p, q):
            stack = [(q, p)]
            while stack:
                a, b = stack.pop()
                if not a and not b:
                    continue
                if a and b and a.val == b.val:
                    stack.append((a.left, b.right))
                    stack.append((a.right,b.left))
                else:
                    return False
            return True
        return Tree(root.left, root.right)
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return Tree(root.left, root.right);

    }
     public boolean Tree(TreeNode p, TreeNode q) {
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
                stack2.push(b.right);
                stack2.push(b.left);
            } else return false;
        }
        return stack1.isEmpty() && stack2.isEmpty();
    }
}
```

层次遍历
```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        from collections import deque 
        
        fontier=deque()
        if not root: return True
        fontier.append(root)
        while fontier: 
            if len(set(fontier)) == 1 and fontier[0] == "#" :break
            bfs_nums=[]
            for _ in range(len(fontier)):
                head = fontier.popleft()
                if head != "#":
                    bfs_nums.append(head.val)
                    fontier.append(head.left if head.left else "#")
                    fontier.append(head.right if head.right else "#")
                else:
                    bfs_nums.append("#")
                    fontier.extend(["#", "#"])     
            if bfs_nums != bfs_nums[::-1]: return False
        return True
```

