#### 树的定义

首先，这是 ```TreeNode``` 的定义，后续会使用到。


```Java [solution 1]
// Definition for a binary tree node.
public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}
```

```Python [solution 1]
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```
<br />


---
#### 直觉

乍一看，这是一个平凡的问题。只需要遍历整棵树，检查 `node.right.val > node.val` 和
 `node.left.val < node.val` 对每个结点是否成立。

![image.png](https://pic.leetcode-cn.com/cfdd62ec84e98f9ea88f885f617b692222c5ec144d228b1838150e18c60be0c2-image.png){:width=500}
{:align=center}

问题是，这种方法并不总是正确。不仅右子结点要大于该节点，整个右子树的元素都应该大于该节点。例如:

![image.png](https://pic.leetcode-cn.com/53f4c7ce658d9611677d12940b06373ae3c900d5c8b94ac3bbf587e152efdba5-image.png){:width=500}
{:align=center}

这意味着我们需要在遍历树的同时保留结点的上界与下界，在比较时不仅比较子结点的值，也要与上下界比较。
<br />
<br />


---
#### 方法一: 递归

上述思路可以用递归法实现。首先将结点的值与上界和下界（如果有）比较。然后，对左子树和右子树递归进行该过程。

<![image.png](https://pic.leetcode-cn.com/e903e554a155e958d789bdd65bd040c75e395998404cc50fb8b3049ca6b55e42-image.png),![image.png](https://pic.leetcode-cn.com/4495980e5afc453a34d3bf3866ce055e3143dd503070a8165760b6ef9362c684-image.png),![image.png](https://pic.leetcode-cn.com/a05b82c34d3087c77a39300ded5a9ea86381e97a20aeeb41241d2c1c40234a41-image.png),![image.png](https://pic.leetcode-cn.com/1edfe34a83d072411612d698695bc609c449a0820fef72046c65ce8394b32947-image.png)>


```Java [solution 2]
class Solution {
  public boolean helper(TreeNode node, Integer lower, Integer upper) {
    if (node == null) return true;

    int val = node.val;
    if (lower != null && val <= lower) return false;
    if (upper != null && val >= upper) return false;

    if (! helper(node.right, val, upper)) return false;
    if (! helper(node.left, lower, val)) return false;
    return true;
  }

  public boolean isValidBST(TreeNode root) {
    return helper(root, null, null);
  }
}
```

```Python [solution 2]
class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(node, lower = float('-inf'), upper = float('inf')):
            if not node:
                return True
            
            val = node.val
            if val <= lower or val >= upper:
                return False

            if not helper(node.right, val, upper):
                return False
            if not helper(node.left, lower, val):
                return False
            return True

        return helper(root)
```

**复杂度分析**

* 时间复杂度 : $O(N)$。每个结点访问一次。
* 空间复杂度 : $O(N)$。我们跟进了整棵树。

<br />
<br />


---
#### 方法二: 迭代

通过使用栈，上面的递归法可以转化为迭代法。这里使用深度优先搜索，比广度优先搜索要快一些。


```Java [solution 3]
class Solution {
  LinkedList<TreeNode> stack = new LinkedList();
  LinkedList<Integer> uppers = new LinkedList(),
          lowers = new LinkedList();

  public void update(TreeNode root, Integer lower, Integer upper) {
    stack.add(root);
    lowers.add(lower);
    uppers.add(upper);
  }

  public boolean isValidBST(TreeNode root) {
    Integer lower = null, upper = null, val;
    update(root, lower, upper);

    while (!stack.isEmpty()) {
      root = stack.poll();
      lower = lowers.poll();
      upper = uppers.poll();

      if (root == null) continue;
      val = root.val;
      if (lower != null && val <= lower) return false;
      if (upper != null && val >= upper) return false;
      update(root.right, val, upper);
      update(root.left, lower, val);
    }
    return true;
  }
}
```

```Python [solution 3]
class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
            
        stack = [(root, float('-inf'), float('inf')), ] 
        while stack:
            root, lower, upper = stack.pop()
            if not root:
                continue
            val = root.val
            if val <= lower or val >= upper:
                return False
            stack.append((root.right, val, upper))
            stack.append((root.left, lower, val))
        return True  
```


**复杂度分析**

* 时间复杂度 : $O(N)$。每个结点访问一次。
* 空间复杂度 : $O(N)$。我们跟进了整棵树。
<br />
<br />


---
#### 方法三：中序遍历

**算法**

我们使用
[中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode/) 
`左子树 -> 结点 -> 右子树`的顺序。

![image.png](https://pic.leetcode-cn.com/af3ae4a01868098cac378e161e9fa4aeea4d0c6693194bd211dd866a8aecb661-image.png){:width=500}
{:align=center}

上面的结点按照访问的顺序标号，你可以按照 `1-2-3-4-5` 的顺序来比较不同的策略。

`左子树 -> 结点 -> 右子树` 意味着对于二叉搜索树而言，每个元素都应该比下一个元素小。

因此，具有 ${O}(N)$ 时间复杂度与 ${O}(N)$ 空间复杂度的算法十分简单:

- 计算中序遍历列表 `inorder`.

- 检查 `inorder`中的每个元素是否小于下一个。

![image.png](https://pic.leetcode-cn.com/6b55fe48b22c1ddae60966e7baf3b8cdc3b5e6d33f0b1ecb14dd800c742e8f2a-image.png){:width=500}
{:align=center}

> 我们需要保留整个`inorder`列表吗？

事实上不需要。每一步最后一个添加的元素就足以保证树是（或不是）二叉搜索树。
因此，我们可以将步骤整合并复用空间。

**实现**


```Java [solution 4]
class Solution {
  public boolean isValidBST(TreeNode root) {
    Stack<TreeNode> stack = new Stack();
    double inorder = - Double.MAX_VALUE;

    while (!stack.isEmpty() || root != null) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      // If next element in inorder traversal
      // is smaller than the previous one
      // that's not BST.
      if (root.val <= inorder) return false;
      inorder = root.val;
      root = root.right;
    }
    return true;
  }
}
```

```Python [solution 4]
class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        stack, inorder = [], float('-inf')
        
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            # If next element in inorder traversal
            # is smaller than the previous one
            # that's not BST.
            if root.val <= inorder:
                return False
            inorder = root.val
            root = root.right

        return True
```


**复杂度分析**

* 时间复杂度 : 最坏情况下（树为二叉搜索树或破坏条件的元素是最右叶结点）为 ${O}(N)$。
 
* 空间复杂度 : ${O}(N)$ 用于存储 `stack`。
