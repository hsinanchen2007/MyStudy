####  概要：
有几种方法可以将 N 叉树编码为二叉树。然而，大多数算法可以追溯到[维基百科](https://en.wikipedia.org/wiki/M-ary_tree#Convert_a_m-ary_tree_to_binary_tree)上的一个算法。

在这里，我们首先直观的说明这个思想，然后将在后面以不同的方式实现它。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9uYXJ5X3RyZWUucG5n?x-oss-process=image/format,png)

简单的说，该算法可以分为两个步骤。我们以上图的 N 叉树为例进行演示。

**步骤一：** 将所有兄弟姐妹链接在一起，就像一个单链表。

原始的 N 叉树中的每个节点将唯一的对应于生成二叉树中的一个节点。

在第一步中，我们首先将所有同级的节点链接在一起，即同一父节点的节点。我们可以通过二叉树的左右指针来链接节点。在这里我们使用右指针。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zaWJsaW5nX2xpc3QucG5n?x-oss-process=image/format,png)

**步骤二：** 将获得的兄弟链表的头与其父节点链接。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9iaW5hcnlfdHJlZS5wbmc?x-oss-process=image/format,png)
注意，经过了以上两个步骤，我们已经将 N 叉树转换为二叉树了！

从图上可能看不出来。但是如果顺时针旋转 45°，就会出现一颗二叉树。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9iaW5hcnlfdHJlZV9mb3JtYXQucG5n?x-oss-process=image/format,png)
基于上述想法，我们可以想象到其他的变换。例如，我们可以使用左指针，而不是右指针。还可以将兄弟链表的最后一个节点与父节点链接。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV92YXJpYW50LnBuZw?x-oss-process=image/format,png)

####  方法一：BFS（广度优先搜索）遍历
遍历树结构通常有两种策略：BFS（广度优先搜索）和DFS（深度优先搜索）。

基于上面的描述，我们可能会发现它很适合用 BFS 策略，因为是逐级遍历节点的，将同级的兄弟节点链接起来。实际上，我们可以用 BFS 实现它，也可以用 DFS 实现它。

**算法：**

我们先从基于 BFS 实现的 `encode(root)`  函数开始：
- 说到 BFS，我们应该记得它是通过队列数据结构实现的。首先，所有的兄弟节点都将按顺序被推入队列。然后依次对队列前端的数据进行处理，这遵循了队列数据结构 FIFO（先进先出）的原则。
- 算法的主体由一个循环组成，循环遍历队列直到队列为空。在循环的每一步，我们从队列的头部弹出一个节点，并对其进行处理。
- 对于弹出的节点，然后在其子节点运行另一个循环。注意，这是循环内的嵌套循环。在嵌套循环的每个步骤中，对于每个子节点，我们做两件事：
	-  首先，我们将这个子节点与邻居节点链接起来。
	- 其次，我们将子节点附加到队列中，以便轮到它作为父节点进行处理，从而对它的子节点进行处理。
- 为了使算法更加健壮，我们可以在函数开头处理 N 叉树为空的情况

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV81LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV82LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV83LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV84LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV85LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV8xMC5wbmc?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV8xMS5wbmc?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV8xMi5wbmc?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9zbGlkZV8xMy5wbmc?x-oss-process=image/format,png)>

```python [solution1-Python]
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Codec:
    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        :type root: Node
        :rtype: TreeNode
        """
        if not root:
            return None

        rootNode = TreeNode(root.val)
        queue = deque([(rootNode, root)])

        while queue:
            parent, curr = queue.popleft()
            prevBNode = None
            headBNode = None
            # traverse each child one by one
            for child in curr.children:
                newBNode = TreeNode(child.val)
                if prevBNode:
                    prevBNode.right = newBNode
                else:
                    headBNode = newBNode
                prevBNode = newBNode
                queue.append((newBNode, child))

            # use the first child in the left node of parent
            parent.left = headBNode

        return rootNode


    def decode(self, data):
        """Decodes your binary tree to an n-ary tree.
        :type data: TreeNode
        :rtype: Node
        """
        if not data:
            return None

        # should set the default value to [] rather than None,
        # otherwise it wont pass the test cases.
        rootNode = Node(data.val, [])

        queue = deque([(rootNode, data)])

        while queue:
            parent, curr = queue.popleft()

            firstChild = curr.left
            sibling = firstChild

            while sibling:
                # Note: the initial value of the children list should not be None, which is assumed by the online judge.
                newNode = Node(sibling.val, [])
                parent.children.append(newNode)
                queue.append((newNode, sibling))
                sibling = sibling.right

        return rootNode
```

```java [solution1-Java]
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
   TreeNode(int x) { val = x; }
}
*/

class Pair<U, V> {
  public U first;
  public V second;

  public Pair(U first, V second) {
    this.first = first;
    this.second = second;
  }
}

class Codec {

  // Encodes an n-ary tree to a binary tree.
  public TreeNode encode(Node root) {
    if (root == null) {
      return null;
    }
    TreeNode newRoot = new TreeNode(root.val);
    Pair<TreeNode, Node> head = new Pair<TreeNode, Node>(newRoot, root);

    // Add the first element to kickoff the loop
    Queue<Pair<TreeNode, Node>> queue = new ArrayDeque<Pair<TreeNode, Node>>();
    queue.add(head);

    while (queue.size() > 0) {
      Pair<TreeNode, Node> pair = queue.remove();
      TreeNode bNode = pair.first;
      Node nNode = pair.second;

      // Encoding the children nodes into a list of TreeNode.
      TreeNode prevBNode = null, headBNode = null;
      for (Node nChild : nNode.children) {
        TreeNode newBNode = new TreeNode(nChild.val);
        if (prevBNode == null) {
          headBNode = newBNode;
        } else {
          prevBNode.right = newBNode;
        }
        prevBNode = newBNode;

        Pair<TreeNode, Node> nextEntry = new Pair<TreeNode, Node>(newBNode, nChild);
        queue.add(nextEntry);
      }

      // Attach the list of children to the left node.
      bNode.left = headBNode;
    }

    return newRoot;
  }

  // Decodes your binary tree to an n-ary tree.
  public Node decode(TreeNode root) {
    if (root == null) {
      return null;
    }
    Node newRoot = new Node(root.val, new ArrayList<Node>());

    // adding the first element to kickoff the loop
    Queue<Pair<Node, TreeNode>> queue = new ArrayDeque<Pair<Node, TreeNode>>();
    Pair<Node, TreeNode> head = new Pair<Node, TreeNode>(newRoot, root);
    queue.add(head);

    while (queue.size() > 0) {
      Pair<Node, TreeNode> entry = queue.remove();
      Node nNode = entry.first;
      TreeNode bNode = entry.second;

      // Decoding the children list
      TreeNode firstChild = bNode.left;
      TreeNode sibling = firstChild;
      while (sibling != null) {
        Node nChild = new Node(sibling.val, new ArrayList<Node>());
        nNode.children.add(nChild);

        // prepare the decoding the children of the child, by standing in the queue.
        Pair<Node, TreeNode> nextEntry = new Pair<Node, TreeNode>(nChild, sibling);
        queue.add(nextEntry);

        sibling = sibling.right;
      }
    }

    return newRoot;
  }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```

对于 `decode(node)` 函数，与我们的 `enconde(node)` 函数类似，也可以用 BFS 的方式实现它。

- 同样，算法的主体是围绕队列数据结构的循环。
- 我们从编码的二叉树根节点开始，将其推入队列。
- 在迭代的每一步，从二叉树中弹出一个节点，然后将该节点的左子节点作为其原始 N 叉树的第一个子节点。
- 然后，通过跟踪二叉树节点的右节点来恢复其余子节点。

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$，其中 $N$ 指的是 N 叉树的节点数。我们遍历树中的每个节点一次。
* 空间复杂度：$\mathcal{O}(L)$，其中 $L$ 指的是同一级别的最大节点数。我们使用队列进行  BFS 遍历，即逐级访问节点。 在任何给定的时刻，队列包含的节点最多扩展到两个级别。假设，一个级别的最大节点数为 $L$。则队列的大小在任何时候都小于 $2L$。因此，`enconde()` 和 `decode()` 的函数空间复杂度都是 $\mathcal{O}(L)$。


####  方法二：DFS（深度优先搜索）遍历
事实证明，我们还可以通过 DFS 遍历策略来实现我们本文开头的想法。

通常情况下，我们采用递归的计数来实现 DFS 算法，这样可以大大简化逻辑。我们可以在函数本身的帮助下实现函数，而不是消除所有迭代步骤。

其思想是，当我们以 DFS 方式逐个节点遍历 N 叉树时，我们可以按照前面方法的逻辑，将节点编码成二叉树。

**算法：**

我们再次以 `encode(node)` 函数为例进行演示。 

该算法的主要思想时，对于每个节点，我们只关心节点本身的编码，调用海曙本身对其每个子节点进行编码。即 `encode(node.children[i])`。

- 在 `encode(node)` 函数的开头，我们创建一个二叉树的节点来包含当前值。
- 然后将 N 叉树第一个子节点作为创建二叉树节点的左节点。我们递归的调用 `encode()` 函数对该节点的子节点进行编码。
- 对于 N 叉树的其余子节点，我们使用二叉树节点的右指针 将它们链接起来。再次，递归的调用 `encode()` 函数来对每个子节点进行编码。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNDMxLzQzMV9ERlMucG5n?x-oss-process=image/format,png)

```python [solution2-Python]
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Codec:

    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        :type root: Node
        :rtype: TreeNode
        """
        if not root:
            return None

        rootNode = TreeNode(root.val)
        if len(root.children) > 0:
            firstChild = root.children[0]
            rootNode.left = self.encode(firstChild)

        # the parent for the rest of the children
        curr = rootNode.left

        # encode the rest of the children
        for i in range(1, len(root.children)):
            curr.right = self.encode(root.children[i])
            curr = curr.right

        return rootNode


    def decode(self, data):
        """Decodes your binary tree to an n-ary tree.
        :type data: TreeNode
        :rtype: Node
        """
        if not data:
            return None

        rootNode = Node(data.val, [])

        curr = data.left
        while curr:
            rootNode.children.append(self.decode(curr))
            curr = curr.right

        return rootNode
```

```java [solution2-Java]
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Codec {

  // Encodes an n-ary tree to a binary tree.
  public TreeNode encode(Node root) {
    if (root == null) {
      return null;
    }

    TreeNode newRoot = new TreeNode(root.val);

    // Encode the first child of n-ary node to the left node of binary tree.
    if (root.children.size() > 0) {
      Node firstChild = root.children.get(0);
      newRoot.left = this.encode(firstChild);
    }

    // Encoding the rest of the sibling nodes.
    TreeNode sibling = newRoot.left;
    for (int i = 1; i < root.children.size(); ++i) {
      sibling.right = this.encode(root.children.get(i));
      sibling = sibling.right;
    }

    return newRoot;
  }

  // Decodes your binary tree to an n-ary tree.
  public Node decode(TreeNode root) {
    if (root == null) {
      return null;
    }

    Node newRoot = new Node(root.val, new ArrayList<Node>());

    // Decoding all the children nodes
    TreeNode sibling = root.left;
    while (sibling != null) {
      newRoot.children.add(this.decode(sibling));
      sibling = sibling.right;
    }

    return newRoot;
  }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。其中 $N$ 指的是 N 叉树的节点数。我们遍历树中的每个节点一次。
* 空间复杂度：$\mathcal{O}(D)$，其中 $D$ 指的是 N 叉树的深度。与 BFS 算法不同，DFS 算法不适用队列数据结构。但是由于函数递归调用，算法将在函数调用中隐式调用堆栈消耗更多的空间。这种调用堆栈空间的消耗是 DFS 算法的主要空间复杂性。任何时刻调用堆栈的大小正好是当前访问节点所在的高度。例如，对于根节点所在的高度为 0，所以堆栈是空的。