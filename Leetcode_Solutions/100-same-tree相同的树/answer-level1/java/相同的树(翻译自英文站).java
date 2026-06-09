> 翻译自英文站 [same-tree solution](https://leetcode.com/problems/same-tree/solution/)

#### 方法 1: 递归

**思路**

最简单的策略是使用递归。检查p和q节点是否不是空，它们的值是否相等。如果所有检查都正常，则递归地为子节点执行相同操作。

**代码**

```java
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
    // p 和 q 均为 null时
    if (p == null && q == null) return true;
    // p 或 q 有一个为null时
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.right, q.right) &&
            isSameTree(p.left, q.left);
  }
}
```

**复杂度分析**

- 时间复杂度：O(N)，其中N是树中的节点数，因为每个节点只访问一次。
- 空间复杂度：O(log(N))， 在最佳情况下即completely balanced tree空间复杂度是O(log(N))，在最坏情况下 completely unbalanced tree空间复杂度是O(N)，和递归次数保持一致。



#### 方法 2: 迭代

**思路**

从根开始，在每次迭代时将当前节点弹出deque。然后执行与方法1中相同的检查：

- `p` 和 `q` 不为空
- `p.val` 和 `q.val` 相等

如果检查正常，则push子节点。

**代码**

```java
class Solution {
  public boolean check(TreeNode p, TreeNode q) {
    // p and q are null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return true;
  }

  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) return true;
    if (!check(p, q)) return false;

    // init deques
    ArrayDeque<TreeNode> deqP = new ArrayDeque<TreeNode>();
    ArrayDeque<TreeNode> deqQ = new ArrayDeque<TreeNode>();
    deqP.addLast(p);
    deqQ.addLast(q);

    while (!deqP.isEmpty()) {
      p = deqP.removeFirst();
      q = deqQ.removeFirst();

      if (!check(p, q)) return false;
      if (p != null) {
        // in Java nulls are not allowed in Deque
        if (!check(p.left, q.left)) return false;
        if (p.left != null) {
          deqP.addLast(p.left);
          deqQ.addLast(q.left);
        }
        if (!check(p.right, q.right)) return false;
        if (p.right != null) {
          deqP.addLast(p.right);
          deqQ.addLast(q.right);
        }
      }
    }
    return true;
  }
}
```

**复杂度分析**

- 时间复杂度 ：O(N) 因为每个节点只访问一次
- 空间复杂度：O(log(N))， 在最佳情况下即completely balanced tree空间复杂度是O(log(N))，在最坏情况下 completely unbalanced tree空间复杂度是O(N)

Analysis written by @[liaison](https://leetcode.com/liaison/) and @[andvary](https://leetcode.com/andvary/)