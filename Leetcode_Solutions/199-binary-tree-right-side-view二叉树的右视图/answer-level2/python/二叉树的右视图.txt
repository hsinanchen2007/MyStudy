![199.mp4](f7deaf22-1a1b-4734-9a17-fe4c75d05641)

#### 初步想法

由于树的形状无法提前知晓，不可能设计出渐近访问少于 $n$ 个结点的算法。因此，我们应该试着寻找线性时间解。带着这个想法，我们来考虑一些同等有效的方案。

#### 方法一：深度优先搜索【通过】

**直觉**

如果按正确的顺序访问每个节点，就可以有效地获得二叉树的右视图。

**算法**

上面提到的顺序之一可以由深度优先搜索定义。在深度优先搜索中，我们总是先访问右子树。这样就保证了当我们访问树的某个特定深度时，我们正在访问的节点总是该深度的最右侧节点。于是，可以存储在每个深度访问的第一个结点，一旦我们知道了树的层数，就可以得到最终的结果数组。

![image.png](https://pic.leetcode-cn.com/80f65d954842dc68509b516d563f846d1f02a31d099027d5a94b49b465e6030c-image.png){:width=200}
{:align=center}

上图表示了问题的一个实例。红色结点自上而下组成答案，边缘以访问顺序标号。

```Python [solution 1]
class Solution(object):
    def rightSideView(self, root):
        rightmost_value_at_depth = dict() # depth -> node.val
        max_depth = -1

        stack = [(root, 0)]
        while stack:
            node, depth = stack.pop()

            if node is not None:
                # maintain knowledge of the number of levels in the tree.
                max_depth = max(max_depth, depth)

                # only insert into dict if depth is not already present.
                rightmost_value_at_depth.setdefault(depth, node.val)

                stack.append((node.left, depth+1))
                stack.append((node.right, depth+1))

        return [rightmost_value_at_depth[depth] for depth in range(max_depth+1)]
```

```Java [solution 1]
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        Map<Integer, Integer> rightmostValueAtDepth = new HashMap<Integer, Integer>();
        int max_depth = -1;

        /* These two stacks are always synchronized, providing an implicit
         * association values with the same offset on each stack. */
        Stack<TreeNode> nodeStack = new Stack<TreeNode>();
        Stack<Integer> depthStack = new Stack<Integer>();
        nodeStack.push(root);
        depthStack.push(0);

        while (!nodeStack.isEmpty()) {
            TreeNode node = nodeStack.pop();
            int depth = depthStack.pop();

            if (node != null) {
                max_depth = Math.max(max_depth, depth);

                /* The first node that we encounter at a particular depth contains
                * the correct value. */
                if (!rightmostValueAtDepth.containsKey(depth)) {
                    rightmostValueAtDepth.put(depth, node.val);
                }

                nodeStack.push(node.left);
                nodeStack.push(node.right);
                depthStack.push(depth+1);
                depthStack.push(depth+1);
            }
        }

        /* Construct the solution based on the values that we end up with at the
         * end. */
        List<Integer> rightView = new ArrayList<Integer>();
        for (int depth = 0; depth <= max_depth; depth++) {
            rightView.add(rightmostValueAtDepth.get(depth));
        }

        return rightView;
    }
}
```

**复杂度分析**

* 时间复杂度 : ${O}(n)$。一棵只有子指针的二叉树是一个只有一个源节点的有向无环图, 从根开始的遍历会经过每个结点一次，加上次线性数量的叶子 `None`。每次访问只需要 ${O}(1)$ 的时间，故 while 循环只需要线性时间。最后，构造右视图的数组需要 ${O}($height of the tree$) = {O}(n)$，因为右视图不可能包括比树本身更多的元素。

* 空间复杂度 : ${O}(n)$。最坏情况下，栈内会包含接近树高度的结点数量。由于采用深度优先，栈中永远不会有来自同一个父节点不同子树的两个结点。换而言之，一个结点的整个右子树将在左子树的任何节点被压栈之前访问。按此逻辑递归处理整棵树，当我们到达树的最长路径（树的高度）的末端时，栈将最大。然而，由于我们对树的结构一无所知，树的高度可能等于$n$，导致空间复杂度为 ${O}(n)$。

---

#### 方法二：广度优先搜索【通过】

**直觉**

就像深度优先搜索可以保证我们最先访问某个深度的最右结点那样，广度优先搜索可以保证我们 _最后_ 访问它。

**算法**

通过执行将左结点排在右结点之前的广度优先搜索，我们对每一层都从左到右访问。因此，通过只保留每个深度最后访问的结点，我们就可以在遍历完整棵树后得到每个深度最右的结点。除了将栈改成 `deque`（双向队列），并去除了`rightmost_value_at_depth`之前的检查外，算法没有别的改动。

![image.png](https://pic.leetcode-cn.com/c7db9c59d74f1d5f1c096315f22b4a00f8cec8c6ac7226766f32923e2b317c9b-image.png){:width=200}
{:align=center}

上图表示了同一个示例，只是方法改成了广度优先搜索。红色结点自上而下组成答案，边缘以访问顺序标号。

```Python [solution 2]
from collections import deque

class Solution(object):
    def rightSideView(self, root):
        rightmost_value_at_depth = dict() # depth -> node.val
        max_depth = -1

        queue = deque([(root, 0)])
        while queue:
            node, depth = queue.popleft()

            if node is not None:
                # maintain knowledge of the number of levels in the tree.
                max_depth = max(max_depth, depth)

                # overwrite rightmost value at current depth. the correct value
                # will never be overwritten, as it is always visited last.
                rightmost_value_at_depth[depth] = node.val

                queue.append((node.left, depth+1))
                queue.append((node.right, depth+1))

        return [rightmost_value_at_depth[depth] for depth in range(max_depth+1)]
```

```Java [solution 2]
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        Map<Integer, Integer> rightmostValueAtDepth = new HashMap<Integer, Integer>();
        int max_depth = -1;

        /* These two Queues are always synchronized, providing an implicit
         * association values with the same offset on each Queue. */
        Queue<TreeNode> nodeQueue = new LinkedList<TreeNode>();
        Queue<Integer> depthQueue = new LinkedList<Integer>();
        nodeQueue.add(root);
        depthQueue.add(0);

        while (!nodeQueue.isEmpty()) {
            TreeNode node = nodeQueue.remove();
            int depth = depthQueue.remove();

            if (node != null) {
                max_depth = Math.max(max_depth, depth);

                /* The last node that we encounter at a particular depth contains
                * the correct value, so the correct value is never overwritten. */
                rightmostValueAtDepth.put(depth, node.val);

                nodeQueue.add(node.left);
                nodeQueue.add(node.right);
                depthQueue.add(depth+1);
                depthQueue.add(depth+1);
            }
        }

        /* Construct the solution based on the values that we end up with at the
         * end. */
        List<Integer> rightView = new ArrayList<Integer>();
        for (int depth = 0; depth <= max_depth; depth++) {
            rightView.add(rightmostValueAtDepth.get(depth));
        }

        return rightView;
    }
}
```

**复杂度分析**

* 时间复杂度 : ${O}(n)$。 **算法** 一节中介绍的改动不会改变时间复杂度。

* 空间复杂度 : ${O}(n)$。由于广度优先搜索逐层访问整棵树，在访问最大的层之前，队列将最大。该层最坏的情况下可能有 $0.5n = {O}(n)$ 大小（一棵完整的二叉树）。

---

**注释**

[^1]: The
[`deque`](https://docs.python.org/3/library/collections.html#collections.deque)
数据类型来自于
[`collections`](https://docs.python.org/3/library/collections.html) 模块，支持从头和尾部的常数时间a ppend/pop 操作。若使用 Python 的 `list`，通过 `list.pop(0)` 去除头部会消耗 ${O}(n)$ 的时间。