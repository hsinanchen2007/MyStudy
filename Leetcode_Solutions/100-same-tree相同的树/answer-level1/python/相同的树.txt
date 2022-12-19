#### 方法一：递归

**直觉**

最简单的策略是使用递归。首先判断 `p` 和 `q` 是不是 `None`，然后判断它们的值是否相等。
若以上判断通过，则递归对子结点做同样操作。

**实现**

<![image.png](https://pic.leetcode-cn.com/ff74097c57e9bfcccd31f44cda2850ae9d287028ac7ac7dff3b409d497b4051d-image.png),![image.png](https://pic.leetcode-cn.com/725bea885f3c88791d8c891e3bb8efe957c206812ddc720127c3e6fd63e95af0-image.png),![image.png](https://pic.leetcode-cn.com/f9fa6061d9bd3109cf04cc5d49de4bd72f558c711c7d51f76afe162e6079acaa-image.png), ![image.png](https://pic.leetcode-cn.com/f1a4ca79a31df13e7048aa95592167e2523c5b7e1535f1216a188f95ca8a74c0-image.png), ![image.png](https://pic.leetcode-cn.com/0e9acd7d480af1ce73b823b70d8672a939794858687020b523554c5b0e33c2b5-image.png),![image.png](https://pic.leetcode-cn.com/fe7d618835cbf3ec88c82896aee4b6c14d675d7a90befd89e7f27255e4addb11-image.png)>


```Python [solution 1]
class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """    
        # p and q are both None
        if not p and not q:
            return True
        # one of p and q is None
        if not q or not p:
            return False
        if p.val != q.val:
            return False
        return self.isSameTree(p.right, q.right) and \
               self.isSameTree(p.left, q.left)
```

```Java [solution 1]
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
    // p and q are both null
    if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.right, q.right) &&
            isSameTree(p.left, q.left);
  }
}
```

**复杂度分析**

* 时间复杂度 : $O(N)$，其中 N 是树的结点数，因为每个结点都访问一次。
 
* 空间复杂度 : 最优情况（完全平衡二叉树）时为 $O(\log(N))$，最坏情况下（完全不平衡二叉树）时为 ${O}(N)$，用于维护递归栈。
<br />
<br />


---
#### 方法二：迭代

**直觉**

从根开始，每次迭代将当前结点从双向队列中弹出。然后，进行方法一中的判断：

- `p` 和 `q` 不是 `None`, 

- `p.val` 等于 `q.val`,

若以上均满足，则压入子结点。

**实现**


```Python [solution 2]
from collections import deque
class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """    
        def check(p, q):
            # if both are None
            if not p and not q:
                return True
            # one of p and q is None
            if not q or not p:
                return False
            if p.val != q.val:
                return False
            return True
        
        deq = deque([(p, q),])
        while deq:
            p, q = deq.popleft()
            if not check(p, q):
                return False
            
            if p:
                deq.append((p.left, q.left))
                deq.append((p.right, q.right))
                    
        return True
```

```Java [solution 2]
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

* 时间复杂度 : $O(N)$，其中 N 是树的结点数，因为每个结点都访问一次。
 
* 空间复杂度 : 最优情况（完全平衡二叉树）时为 $O(\log(N))$，最坏情况下（完全不平衡二叉树）时为 ${O}(N)$，用于维护双向队列。