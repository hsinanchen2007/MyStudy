根据定义，一棵二叉树 $T$ 存在节点 $p\in T$，满足 $|\texttt{height}(p.left) - \texttt{height}(p.right)| > 1$ 时，它是不平衡的。下图中每个节点的高度都被标记出来，高亮区域是一棵不平衡子树。

![](https://pic.leetcode-cn.com/Figures/110/110-unbalanced-wheight-highlighted.png){:width=450}

> 平衡子树暗示了一个事实，每棵子树也是一个子问题。
> 现在的问题是：按照什么顺序处理这些子问题？


#### 方法一：自顶向下的递归

**算法**

定义方法 $\texttt{height}$，用于计算任意一个节点 $p\in T$ 的高度：

$$
\texttt{height}(p) = 
\begin{cases}
-1 & p \text{ is an empty subtree i.e. } \texttt{null}\\
1 + \max(\texttt{height}(p.left), \texttt{height}(p.right)) & \text{ otherwise}
\end{cases}
$$

接下来就是比较每个节点左右子树的高度。在一棵以 $r$ 为根节点的树 
$T$ 中，只有每个节点左右子树高度差不大于 1 时，该树才是平衡的。因此可以比较每个节点左右两棵子树的高度差，然后向上递归。

```python [solution1-Python]
isBalanced(root):
    if (root == NULL):
        return true
    if (abs(height(root.left) - height(root.right)) > 1):
        return false
    else:
        return isBalanced(root.left) && isBalanced(root.right)

```

```java [solution1-Java]
class Solution {
  // Recursively obtain the height of a tree. An empty tree has -1 height
  private int height(TreeNode root) {
    // An empty tree has height -1
    if (root == null) {
      return -1;
    }
    return 1 + Math.max(height(root.left), height(root.right));
  }

  public boolean isBalanced(TreeNode root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == null) {
      return true;
    }

    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return Math.abs(height(root.left) - height(root.right)) < 2
        && isBalanced(root.left)
        && isBalanced(root.right);
  }
};
```

```cpp [solution1-Cpp]
class Solution {
private:
  // Recursively obtain the height of a tree. An empty tree has -1 height
  int height(TreeNode* root) { 
    // An empty tree has height -1
    if (root == NULL) {
      return -1;
    }
    return 1 + max(height(root->left), height(root->right));
  }
public:
  bool isBalanced(TreeNode* root) {
    // An empty tree satisfies the definition of a balanced tree
    if (root == NULL) {
      return true;
    }

    // Check if subtrees have height within 1. If they do, check if the
    // subtrees are balanced
    return abs(height(root->left) - height(root->right)) < 2 &&
      isBalanced(root->left) &&
      isBalanced(root->right);
  }
};
```

```python [solution1-Python]
class Solution:
    # Compute the tree's height via recursion
    def height(self, root: TreeNode) -> int:
        # An empty tree has height -1
        if not root:
            return -1
        return 1 + max(self.height(root.left), self.height(root.right))
    
    def isBalanced(self, root: TreeNode) -> bool:
        # An empty tree satisfies the definition of a balanced tree
        if not root:
            return True

        # Check if subtrees have height within 1. If they do, check if the
        # subtrees are balanced
        return abs(self.height(root.left) - self.height(root.right)) < 2 \
            and self.isBalanced(root.left) \
            and self.isBalanced(root.right)
        
```

<![750](https://pic.leetcode-cn.com/Figures/110/topDown-0.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-1.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-2.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-3.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-4.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-5.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-6.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-7.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-8.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-9.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-10.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-11.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-12.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-13.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-14.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-15.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-16.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-17.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-18.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-19.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-20.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-21.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-22.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-23.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-24.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-25.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-26.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-27.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-28.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-29.png),![750](https://pic.leetcode-cn.com/Figures/110/topDown-30.png)>

**复杂度分析**

* 时间复杂度：$\mathcal{O}(n\log n)$。

    * 对于每个深度为 $d$ 的节点 $p$，$\texttt{height}(p)$ 被调用 $p$ 次。

    * 首先，需要知道一棵平衡二叉树可以拥有的节点数量。令 $f(h)$ 表示一棵高度为 $h$ 的平衡二叉树需要的最少节点数量。

    $$
    f(h) = f(h - 1) + f(h - 2) + 1
    $$
    
    这与斐波那契数列的递归关系几乎相同。实际上，它的复杂度分析方法也和斐波那契数列一样。$f(h)$ 的下界是 $f(h) = \Omega\left(\left(\frac{3}{2}\right)^h\right)$。

    $$                                                                          
     \begin{align}                                                                   
    f(h+1) &= f(h) + f(h-1) + 1 \\                                                  
    &> f(h) + f(h-1) & \qquad\qquad \text{This is the fibonacci sequence}\\               
    &\geq \left(\frac{3}{2}\right)^{h} + \left(\frac{3}{2}\right)^{h-1} & \text{via our claim} \\
    &= \frac{5}{2} \left(\frac{3}{2}\right)^{h-1}\\
    &> \frac{9}{4} \left(\frac{3}{2}\right)^{h-1} & \frac{9}{4} < \frac{5}{2}\\
    &> \left(\frac{3}{2}\right)^{h+1}
    \end{align}                                                                     
    $$    

    因此，平衡二叉树的高度 $h$ 不大于 $\mathcal{O}(\log_{1.5}(n))$。有了这个限制，可以保证方法 $\texttt{height}$ 在每个节点上调用不超过 $\mathcal{O}(\log n)$ 次。
 
    * 如果树是倾斜的，高度达到 \mathcal{O}(n)$，算法没有尽早结束，最终会达到 $\mathcal{O}(n^2)$ 的复杂度。
    但是请注意：只要有子节点的两棵子树高度差大于 1，就会停止递归。实际上，如果树是完全倾斜的，仅需要检查最开始的两棵子树。
        
* 空间复杂度：$\mathcal{O}(n)$。如果树完全倾斜，递归栈可能包含所有节点。

**一个有趣的事实**：$f(n) = f(n-1) + f(n-2) + 1$ 被称为斐波那契数列。


#### 方法二：自底向上的递归

**思路** 

方法一计算 $\texttt{height}$ 存在大量冗余。每次调用 $\texttt{height}$ 时，要同时计算其子树高度。但是自底向上计算，每个子树的高度只会计算一次。可以递归先计算当前节点的子节点高度，然后再通过子节点高度判断当前节点是否平衡，从而消除冗余。

**算法**

使用与方法一中定义的 $\texttt{height}$ 方法。自底向上与自顶向下的逻辑相反，首先判断子树是否平衡，然后比较子树高度判断父节点是否平衡。算法如下：

> 检查子树是否平衡。如果平衡，则使用它们的高度判断父节点是否平衡，并计算父节点的高度。

```java [solution2-Java]
// Utility class to store information from recursive calls
final class TreeInfo {
  public final int height;
  public final boolean balanced;

  public TreeInfo(int height, boolean balanced) {
    this.height = height;
    this.balanced = balanced;
  }
}

class Solution {
  // Return whether or not the tree at root is balanced while also storing
  // the tree's height in a reference variable.
  private TreeInfo isBalancedTreeHelper(TreeNode root) {
    // An empty tree is balanced and has height = -1
    if (root == null) {
      return new TreeInfo(-1, true);
    }

    // Check subtrees to see if they are balanced.
    TreeInfo left = isBalancedTreeHelper(root.left);
    if (!left.balanced) {
      return new TreeInfo(-1, false);
    }
    TreeInfo right = isBalancedTreeHelper(root.right);
    if (!right.balanced) {
      return new TreeInfo(-1, false);
    }

    // Use the height obtained from the recursive calls to
    // determine if the current node is also balanced.
    if (Math.abs(left.height - right.height) < 2) {
      return new TreeInfo(Math.max(left.height, right.height) + 1, true);
    }
    return new TreeInfo(-1, false);
  }

  public boolean isBalanced(TreeNode root) {
    return isBalancedTreeHelper(root).balanced;
  }
};
```

```cpp [solution2-Cpp]
class Solution {
private:
  // Return whether or not the tree at root is balanced while also storing
  // the tree's height in a reference variable. 
  bool isBalancedTreeHelper(TreeNode* root, int& height) {
    // An empty tree is balanced and has height = -1
    if (root == NULL) {
      height = -1;
      return true;
    }

    // Check subtrees to see if they are balanced. If they are, check if the 
    // current node is also balanced using the heights obtained from the 
    // recursive calls.
    int left, right;
    if (isBalancedTreeHelper(root->left, left)  &&
        isBalancedTreeHelper(root->right, right) &&
        abs(left - right) < 2) {
      // Store the current tree's height
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
public:
  bool isBalanced(TreeNode* root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};
```

```python [solution2-Python]
class Solution:
    # Return whether or not the tree at root is balanced while also returning
    # the tree's height
    def isBalancedHelper(self, root: TreeNode) -> (bool, int):
        # An empty tree is balanced and has height -1
        if not root:
            return True, -1
        
        # Check subtrees to see if they are balanced. 
        leftIsBalanced, leftHeight = self.isBalancedHelper(root.left)
        if not leftIsBalanced:
            return False, 0
        rightIsBalanced, rightHeight = self.isBalancedHelper(root.right)
        if not rightIsBalanced:
            return False, 0
        
        # If the subtrees are balanced, check if the current tree is balanced
        # using their height
        return (abs(leftHeight - rightHeight) < 2), 1 + max(leftHeight, rightHeight)
        
    def isBalanced(self, root: TreeNode) -> bool:
        return self.isBalancedHelper(root)[0]

```

<![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-0.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-1.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-2.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-3.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-4.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-5.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-6.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-7.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-8.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-9.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-10.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-11.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-12.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-13.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-14.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-15.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-16.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-17.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-18.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-19.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-20.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-21.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-22.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-23.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-24.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-25.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-26.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-27.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-28.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-29.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-30.png),![750](https://pic.leetcode-cn.com/Figures/110/bottomUp-31.png)>

**复杂度分析**

* 时间复杂度：$\mathcal{O}(n)$，计算每棵子树的高度和判断平衡操作都在恒定时间内完成。

* 空间复杂度：$\mathcal{O}(n)$，如果树不平衡，递归栈可能达到 $\mathcal{O}(n)$。