####  概述
在研究这个问题的解决方案之前，让我们来总结以下问题的陈述中要求我们实现什么。我们有一个迭代器类，它有两个函数，即 `next()` 和 `hasNext()`。`hasNext()` 函数的作用是：返回一个布尔值，表示二叉搜索树中是否还有元素。`next()` 函数返回二叉搜索树中下一个最小元素。因此，我们第一次调用 `next()` 函数时，应返回二叉搜索树中的最小元素；同理，当我们最后一次调用 `next()` 时，应返回二叉搜索树中的最大元素。

你可能想知道迭代器的作用是什么。本质上，迭代器可以用于迭代任何容器的对象。就本题而言，容器是一个二叉搜索树。如果定义了这样的一个迭代器，那么遍历的逻辑就可以被抽象出来，我们可以使用迭代器按一定顺序处理元素。

```
1. new_iterator = BSTIterator(root);
2. while (new_iterator.hasNext())
3.     process(new_iterator.next());
```

现在我们知道了为数据结构设计一个迭代器类背后的原因，通常，迭代器只是逐个遍历容器的每个元素。对于二叉搜索树，我们希望迭代器以升序返回元素。

二叉搜索树的一个重要的特性是是二叉搜索树的中序序列是升序序列；因此，中序遍历是该解决方案的核心。

![在这里插入图片描述](https://pic.leetcode-cn.com/a25da29b14cf14f84a96a06454c1cd4fd264854e8408b8bde4ba31419c212317-file_1579412919657)
![在这里插入图片描述](https://pic.leetcode-cn.com/d9dbcff23bf24e159c5a10867e1f040fdb0d0821958fc98670a49e1457e6c041-file_1579412919635)
![在这里插入图片描述](https://pic.leetcode-cn.com/daa306d3315a480b5f3730811c144ad5cc21984e389dc6f8b2f30dab47c14932-file_1579412919660)
![在这里插入图片描述](https://pic.leetcode-cn.com/d8ac113f3d3875bbb996a2f418f041d2157ce0074b7c3511885b249e985ed0e8-file_1579412919650)
![在这里插入图片描述](https://pic.leetcode-cn.com/440125a0660e69298d7de22e6d535139c98eb0b371636a68232810b47a048b84-file_1579412919647)
![在这里插入图片描述](https://pic.leetcode-cn.com/e0507733b4cb1db2d4cde47092914e8c4a26323347924c2c95512f573cbf8063-file_1579412919645)
![在这里插入图片描述](https://pic.leetcode-cn.com/3eef585a1b69436efcba0d63e1d8fc0cf0d5dd0e4f05939e266896368291c7f2-file_1579412919662)
![在这里插入图片描述](https://pic.leetcode-cn.com/77c3ca5b4909fce26020796d158c6fc52d5860a700bda2e3cf0e3504a97668f7-file_1579412919588)
![在这里插入图片描述](https://pic.leetcode-cn.com/f83ab4bef242a7242f9351f42e684093a3d660196da17584f43cb05d583e52cb-file_1579412919655)
![在这里插入图片描述](https://pic.leetcode-cn.com/974dc0d78969dc65fcdbe58df52b479cfb849815902b0ccc01e198cccde656f0-file_1579412919642)
![在这里插入图片描述](https://pic.leetcode-cn.com/cd6236518d3a172f1a06ba4b38f9f423f6533e0c3647548c6b53bdc4ea9b464c-file_1579412919584)
![在这里插入图片描述](https://pic.leetcode-cn.com/a0a9bc99d6011a3f99f87c9179000b090e5e5251139125ba210a1e7254dacfbe-file_1579412919653)
![在这里插入图片描述](https://pic.leetcode-cn.com/9472057d0c909ace74a9b4462d2bf88138cb2c2aa66d8645a3a026197f3956b8-file_1579412919571)
![在这里插入图片描述](https://pic.leetcode-cn.com/7dc688436193e6cc5f88d2f64c933bfe7f51998a62ef3f57db3f5bf12ba4a1d8-file_1579412919628)
![在这里插入图片描述](https://pic.leetcode-cn.com/e68e3aef42bbe35cf6432712f9b84e57734935500c5683a31612e6b101c0188e-file_1579412919631)
![在这里插入图片描述](https://pic.leetcode-cn.com/65c2eeff97c49abd33574f8d46a69cd8ec578b36bd46a2fb154068e23e865e1c-file_1579412919637)
![在这里插入图片描述](https://pic.leetcode-cn.com/7dc8e52c4624046e9a33aa6442ae561f662b1c2d542533dbb1d105fb34803d13-file_1579412919664)
![在这里插入图片描述](https://pic.leetcode-cn.com/a5c007ff26f9eca596de64a7af082e394a9511523923434edf394ccc8de29533-file_1579412919640)
![在这里插入图片描述](https://pic.leetcode-cn.com/9d18ee11ae916fb47b0d462e8433490edee72c3418245d2668947a83c4fdce8c-file_1579412919626)

####  方法一：扁平化二叉搜索树
在计算机程序设计中，迭代器是使程序员能够遍历容器的对象。这是维基百科对迭代器的定义。当前，实现迭代器的最简单的方法是在类似数组的容器接口上。如果我们有一个数组，则我们只需要一个指针或者索引，就可以轻松的实现函数 `next()` 和 `hasNext()`。

因此，我们要研究的第一种方法就是基于这种思想。我们将使用额外的数组，并将二叉搜索树展开存放到里面。我们想要数组的元素按升序排序，则我们应该对二叉搜索树进行中序遍历，然后我们在数组中构建迭代器函数。

**算法：**

1. 初始化一个空数组用来存放二叉搜索树的中序序列。
2. 我们按中序遍历二叉搜索树，按照左中右的顺序处理节点。
3. 一旦所有节点都在数组中，则我们只需要一个指针或索引来实现 `next()` 和 `hasNext` 这两个函数。每当调用 `hasNext()` 时，我们只需要检查索引是否达到数组末尾。每当调用 `next()` 时，我们只需要返回索引指向的元素，并向前移动一步，以模拟迭代器的进度。

```python [solution1-Python]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        
        # Array containing all the nodes in the sorted order
        self.nodes_sorted = []
        
        # Pointer to the next smallest element in the BST
        self.index = -1
        
        # Call to flatten the input binary search tree
        self._inorder(root)
        
    def _inorder(self, root):
        if not root:
            return
        self._inorder(root.left)
        self.nodes_sorted.append(root.val)
        self._inorder(root.right)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        self.index += 1
        return self.nodes_sorted[self.index]

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.index + 1 < len(self.nodes_sorted)
```

```java [solution1-Java]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {

    ArrayList<Integer> nodesSorted;
    int index;

    public BSTIterator(TreeNode root) {

        // Array containing all the nodes in the sorted order
        this.nodesSorted = new ArrayList<Integer>();
        
        // Pointer to the next smallest element in the BST
        this.index = -1;
        
        // Call to flatten the input binary search tree
        this._inorder(root);
    }

    private void _inorder(TreeNode root) {

        if (root == null) {
            return;
        }

        this._inorder(root.left);
        this.nodesSorted.add(root.val);
        this._inorder(root.right);
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        return this.nodesSorted.get(++this.index);
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return this.index + 1 < this.nodesSorted.size();
    }
}
```

**复杂度分析**

* 时间复杂度：构造迭代器花费的时间为 $O(N)$，问题陈述只要求我们分析两个函数的复杂性，但是在实现类时，还要注意初始化类对象所需的时间；在这种情况下，时间复杂度与二叉搜索树中的节点数成线性关系。
	* `next()`：$O(1)$
	* `hasNext()`：$O(1)$
* 空间复杂度：$O(N)$，由于我们创建了一个数组来包含二叉搜索树中的所有节点值，这不符合问题陈述中的要求，任一函数的最大空间复杂度应为 $O(h)$，其中 $h$ 指的是树的高度，对于平衡的二叉搜索树，高度通常为 $logN$。


####  方法二：受控递归
我们前面使用的方法在空间上与二叉搜索树中的节点数呈线性关系。然而，我们不得不使用这种方法的原因是我们可以在数组上迭代，且我们不能够暂停递归，然后在某个时候启动它。

但是，如果我们可以模拟中序遍历的受控递归，那么除了堆栈用于模拟递归的空间之外，实际上不需要使用任何其他空间。

因此，这种方法的本质上是使用自定义的栈来模拟中序遍历。也就是说，我们将采用迭代的方式来模拟中序遍历，而不是采用递归的方法；这样做的过程中，我们能够轻松的实现这两个函数的调用，而不是用其他额外的空间。

然而，就这两个函数的复杂性而言，会有点复杂，我们需要花一些时间来理解这种方法是否符合问题所说的渐近复杂性的要求。让我们更加具体的看一下这个算法。

**算法：**

1. 初始化一个空栈 `S`，用于模拟二叉搜索树的中序遍历。中序遍历我们采用与之前相同的方法，只是我们现在使用的是自己的栈而不是系统的堆栈。由于我们使用自定义的数据结构，因此可以随时暂停和恢复递归。
2. 我们还要实现一个帮助函数，在实现中将一次又一次的调用它。这个函数叫 `_inorder_left`，它将给定节点中的所有左子节点添加到栈中，直到节点没有左子节点为止。如下：

```
def inorder_left(root):
   while (root):
     S.append(root)
     root = root.left
```

3. 第一次调用 `next()` 函数时，必须返回二叉搜索树的最小元素，然后我们模拟递归必须向前移动一步，即移动到二叉搜索树的下一个最小元素上。栈的顶部始终包含 `next()` 函数返回的元素。`hasNext()` 很容易实现，因为我们只需要检查栈是否为空。
4. 首先，给定二叉搜索树的根节点，我们调用函数 `_inorder_left`，这确保了栈顶部始终包含了 `next()` 函数返回的元素。
5. 假设我们调用 `next()`，我们需要返回二叉搜索树中的下一个最小元素，即栈的顶部元素。有两种可能性：
	-  一个是栈顶部的节点是一个叶节点。这是最好的情况，因为我们什么都不用做，只需将节点从栈中弹出并返回其值。所以这是个常数时间的操作。
	- 另一个情况是栈顶部的节点拥有右节点。我们不需要检查左节点，因为左节点已经添加到栈中了。栈顶元素要么没有左节点，要么左节点已经被处理了。如果栈顶部拥有右节点，那么我们需要对右节点上调用帮助函数。该时间复杂度取决于树的结构。
6. `next()` 函数调用中，获取下一个最小的元素不需要花太多时间，但是要保证栈顶元素是 `next()` 函数返回的元素方面花费了一些时间。  

```python [solution2-Python]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        
        # Stack for the recursion simulation
        self.stack = []
        
        # Remember that the algorithm starts with a call to the helper function
        # with the root node as the input
        self._leftmost_inorder(root)
        
    def _leftmost_inorder(self, root):
        
        # For a given node, add all the elements in the leftmost branch of the tree
        # under it to the stack.
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        
        # Node at the top of the stack is the next smallest element
        topmost_node = self.stack.pop()
        
        # Need to maintain the invariant. If the node has a right child, call the 
        # helper function for the right child
        if topmost_node.right:
            self._leftmost_inorder(topmost_node.right)
        return topmost_node.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.stack) > 0
```

```java [solution2-Java]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {

    Stack<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        
        // Stack for the recursion simulation
        this.stack = new Stack<TreeNode>();
        
        // Remember that the algorithm starts with a call to the helper function
        // with the root node as the input
        this._leftmostInorder(root);
    }

    private void _leftmostInorder(TreeNode root) {
      
        // For a given node, add all the elements in the leftmost branch of the tree
        // under it to the stack.
        while (root != null) {
            this.stack.push(root);
            root = root.left;
        }
    }

    /**
     * @return the next smallest number
     */
    public int next() {
        // Node at the top of the stack is the next smallest element
        TreeNode topmostNode = this.stack.pop();

        // Need to maintain the invariant. If the node has a right child, call the 
        // helper function for the right child
        if (topmostNode.right != null) {
            this._leftmostInorder(topmostNode.right);
        }

        return topmostNode.val;
    }

    /**
     * @return whether we have a next smallest number
     */
    public boolean hasNext() {
        return this.stack.size() > 0;
    }
}
```

**复杂度分析**

* 时间复杂度：
	* `hasNext()`：若栈中还有元素，则返回 `true`，反之返回 `false`。所以这是一个 $O(1)$ 的操作。
	* `next()`：包含了两个主要步骤。一个是从栈中弹出一个元素，它是下一个最小的元素。这是一个 $O(1)$ 的操作。然而，随后我们要调用帮助函数 `_inorder_left `，它需要递归的，将左节点添加到栈上，是线性时间的操作，最坏的情况下为 $O(N)$。但是我们只对含有右节点的节点进行调用，它也不会总是处理 N 个节点。只有当我们有一个倾斜的树，才会有 N 个节点。因此该操作的平均时间复杂度仍然是 $O(1)$，符合问题中所要求的。
* 空间复杂度：$O(h)$，使用了一个栈来模拟递归。