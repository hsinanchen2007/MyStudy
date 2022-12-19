#### 初始想法

此题目要求我们在一个二叉搜索树上修改渐进线性数目个节点，所以一个高效的解法应该遍历每个节点一次。解法的关键在于应该按照节点值降序遍历所有节点，同时记录我们已经遍历过的节点值的和，并把这个和加到当前节点的值中。这种遍历树的方法被称作 *反序中序遍历* ，它确保我们按我们想要的顺序遍历每一个节点。这个算法的基本思想是遍历一个没有遍历过的节点之前，先将大于点值的点都遍历一遍。这些点都在哪里呢？就在右子树里面。

#### 方法  1：回溯 [Accepted]

**想法**

一个反序中序遍历的方法是通过递归实现。通过调用栈回到之前的节点，我们可以轻松地反序遍历所有节点。

**算法**

在递归方法中，我们维护一些递归调用过程中可以访问和修改的全局变量。首先我们判断当前访问的节点是否存在，如果存在就递归右子树，递归回来的时候更新总和和当前点的值，然后递归左子树。如果我们分别正确地递归 `root.right` 和 `root.left` ，那么我们就能正确地用大于某个节点的值去更新此节点，然后才遍历比它小的值。

```java []
class Solution {
    private int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        if (root != null) {
            convertBST(root.right);
            sum += root.val;
            root.val = sum;
            convertBST(root.left);
        }
        return root;
    }
}
```

```python []
class Solution(object):
    def __init__(self):
        self.total = 0

    def convertBST(self, root):
        if root is not None:
            self.convertBST(root.right)
            self.total += root.val
            root.val = self.total
            self.convertBST(root.left)
        return root
```

**复杂度分析**

* 时间复杂度： $\mathcal{O}(n)$

    一个二叉树是没有环的，所以 `convertBST` 对于每个节点来说不会被调用超过 1 次。除去递归调用以外， `convertBST` 做的工作是常数时间的，所以线性次调用 `convertBST` 的运行时间是线性时间的。

* 空间复杂度： $\mathcal{O}(n)$

    使用之前的结论 `convertBST` 会被调用线性次，我们可以知道整个算法的空间复杂度也是线性的。考虑最坏情况，一棵树只有右子树（或者只有左子树），调用栈会一直增长直到到达叶子节点，也就是包含 $n$ 个节点。

#### 方法 2：使用栈迭代 [Accepted]

**想法**

如果我们不想使用递归，我们可以通过迭代和栈来实现函数调用栈的过程。

**算法**

一个描述迭代栈的方法就是通过递归的思想。首先我们初始化一个空的栈并把根节点作为当前节点。然后只要在栈中有未遍历节点或者 `node` 节点不为空，我们就将当前节点到最右边叶子路径上的点全部压入栈中。这与递归过程中我们总是先走右子树的思路是一致的，这个思路确保我们总是降序遍历所有节点的值。接下来，我们访问栈顶节点，并考虑它的左子树，这就像我们递归中先遍历当前节点再遍历它的左子树的思路。最后，我们的栈为空并且 `node` 指向树中最小节点的左孩子 `null` ，循环结束。

```java []
class Solution {
    public TreeNode convertBST(TreeNode root) {
        int sum = 0;
        TreeNode node = root;
        Stack<TreeNode> stack = new Stack<TreeNode>();

        while (!stack.isEmpty() || node != null) {
            /* push all nodes up to (and including) this subtree's maximum on
             * the stack. */
            while (node != null) {
                stack.add(node);
                node = node.right;
            }

            node = stack.pop();
            sum += node.val;
            node.val = sum;

            /* all nodes with values between the current and its parent lie in
             * the left subtree. */
            node = node.left;
        }

        return root;
    }
}
```

```python []
class Solution(object):
    def convertBST(self, root):
        total = 0
        
        node = root
        stack = []
        while stack or node is not None:
            # push all nodes up to (and including) this subtree's maximum on
            # the stack.
            while node is not None:
                stack.append(node)
                node = node.right

            node = stack.pop()
            total += node.val
            node.val = total

            # all nodes with values between the current and its parent lie in
            # the left subtree.
            node = node.left

        return root
```

**复杂度分析**

* 时间复杂度： $\mathcal{O}(n)$

    最关键一点是每一个节点会被压入栈中恰好一次。每个点会被压入栈中 *至少* 一次的结论是显而易见的，否则的话至少有一个点与根不连通。一个点被压入栈中一定是 `node` 在外面的 `while` 循环中初始时指向了该点，或者从某个点出发只往右边走走道了该点。同时注意到每次循环迭代的最后， `node` 指向一个点的左孩子并被压入栈中（后面会被弹出）。由于外层 `while` 循环总是从 `node` 指向 `None` 、根、一个已访问节点的左孩子开始的，所以不会有节点被重新访问。

* 空间复杂度：$\mathcal{O}(n)$

    如果我们假设上面的逻辑是正确的，那么每个节点只会被压入栈中恰好一次的结论表明栈最多只会包含 $n$ 个节点。算法其他的部分只会用常数的空间，所以总空间是线性的。

#### 方法 3：反序中序 Morris 遍历 [Accepted]

**想法**

有一种很机智的办法只用线性时间和常数空间来实现中序遍历，这种方法由 J. H. Morris 在他 1979 年的论文 "Traversing Binary Trees Simply and Cheaply" 中首次提出。总的来说，递归和迭代栈的方法在遍历左子树后返回当前节点，都牺牲了线性的空间。 Morris 遍历使用指针 `null` 指针在左子树以外创建了一个临时指针，使得遍历只需要使用常数额外空间。为了应用于此题，我们只需要交换所有的“左”“右”引用，就可以反转整个遍历过程。

**算法**

首先，我们初始化 `node` ，它指向根。然后，在 `node` 指向 `null` 之前（具体指树中最小值节点的左孩子 `null`），我们重复如下过程：先考虑当前节点是否有右子树，如果没有右子树那么所有大于当前节点的值都已遍历，我们就可以更新当前节点并进入左子树。如果还有右子树，那么至少有一个未访问过的更大值，我们必须先访问右子树。我们通过辅助函数 `getSuccessor` ，得到一个引用来记录当前节点中序遍历的下一个节点（最小大于当前值的节点），这个节点是恰好先于我们访问当前节点之前的节点，所以根据定义这一下一节点有一个为 `null` 的左孩子指针（否则它不是当前节点的下一个节点）。所以当我们首次找到一个节点的下一节点时，我们将该下一节点的左指针指向当前节点。这样，当我们遍历完当前节点的右子树时，右子树中最左边节点的左指针会是我们的临时指针，它指向当前节点，我们就可以快速回到当前节点中来。如果我们发现从下一节点的左指针回到了当前节点，说明右子树已经遍历完了，我们可以删除这个临时指针并继续递归左子树。

![image.png](https://pic.leetcode-cn.com/91b7c7b9b3756ff0263cb8f63e6a4e5655e033778ae88549ed010d73627f9351-image.png){:width=300}
{:align="center"}

上图说明了 Morris 遍历过程中一棵修改了的树。左指针被标为蓝色，右指针标为红色。虚线边表明遍历过程中的临时指针（在遍历结束之后会被删除）。注意到蓝色的边也可以标为虚线边，就像我们使用的“下一节点”的左空指针一样。除此以外，我们注意到每一个有右子树的节点都有一个“下一节点”的边指向自己。

```java []
class Solution {
    /* Get the node with the smallest value greater than this one. */
    private TreeNode getSuccessor(TreeNode node) {
        TreeNode succ = node.right;
        while (succ.left != null && succ.left != node) {
            succ = succ.left;
        }
        return succ;
    }

    public TreeNode convertBST(TreeNode root) {
        int sum = 0;
        TreeNode node = root;

        while (node != null) {
            /* 
             * If there is no right subtree, then we can visit this node and
             * continue traversing left.
             */
            if (node.right == null) {
                sum += node.val;
                node.val = sum;
                node = node.left;
            }
            /* 
             * If there is a right subtree, then there is at least one node that
             * has a greater value than the current one. therefore, we must
             * traverse that subtree first.
             */
            else {
                TreeNode succ = getSuccessor(node);
                /* 
                 * If the left subtree is null, then we have never been here before.
                 */
                if (succ.left == null) {
                    succ.left = node;
                    node = node.right;
                }
                /* 
                 * If there is a left subtree, it is a link that we created on a
                 * previous pass, so we should unlink it and visit this node.
                 */
                else {
                    succ.left = null;
                    sum += node.val;
                    node.val = sum;
                    node = node.left;
                }
            }
        }
        
        return root;
    }
}
```

```python []
class Solution(object):
    def convertBST(self, root):
        # Get the node with the smallest value greater than this one.
        def get_successor(node):
            succ = node.right
            while succ.left is not None and succ.left is not node:
                succ = succ.left
            return succ
                
        total = 0
        node = root
        while node is not None:
            # If there is no right subtree, then we can visit this node and
            # continue traversing left.
            if node.right is None:
                total += node.val
                node.val = total
                node = node.left
            # If there is a right subtree, then there is a node that has a
            # greater value than the current one. therefore, we must traverse
            # that node first.
            else:
                succ = get_successor(node)
                # If there is no left subtree (or right subtree, because we are
                # in this branch of control flow), make a temporary connection
                # back to the current node.
                if succ.left is None:
                    succ.left = node
                    node = node.right
                # If there is a left subtree, it is a link that we created on
                # a previous pass, so we should unlink it and visit this node.
                else:
                    succ.left = None
                    total += node.val
                    node.val = total
                    node = node.left
        
        return root
```

**复杂度分析**

* 时间复杂度： $\mathcal{O}(n)$

    尽管 Morris遍历比起其他方法来说额外多做了一些工作，但只是一个常数级别的。具体来说，如果我们可以证明一条边被遍历了不超过常数 $k$ 次，那么这个算法就是一个渐进线性的复杂度。首先注意到 `getSuccessor` 每个节点最多会调用 2 次，在第一次调用时，会有一个临时指针指向当前节点，第二次调用时，临时指针被删除。然后这个算法会进入左子树且不再会回到该节点。所以每条边最多被遍历 3 次：一次是移动 `node` 指针，另外两次遍历是调用 `getSuccessor` 时。

* 空间复杂度： $\mathcal{O}(1)$

    由于我们只操作已经存在的指针， Morris 只需要常数的额外空间。
