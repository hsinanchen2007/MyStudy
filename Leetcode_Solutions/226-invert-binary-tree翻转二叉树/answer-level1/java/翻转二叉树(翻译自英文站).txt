
#### 方法一：递归

这是一个经典的树问题，最适合递归方法。

**算法**

空树翻转之后还是空树。根节点（root）的左子节点及其所有的子孙节点构成根节点的左子树（left subtree），同样的，根节点（root）的右子节点及其所有的子孙节点构成根节点的右子树（right subtree）。因此翻转一个二叉树，就是把根节点的左子树翻转一下，同样的把右子树翻转一下，在交换左右子树就可以了。

```java
public TreeNode invertTree(TreeNode root) {
    if (root == null) {
        return null;
    }
    TreeNode right = invertTree(root.right);
    TreeNode left = invertTree(root.left);
    root.left = right;
    root.right = left;
    return root;
}
```

**复杂度分析**

- 时间复杂度：`O(n)`，由于树中的每个节点仅被访问一次，因此时间复杂度为`O(n)`，其中`n`是树中的节点数。我们不能做得更好，因为我们必须访问每个节点来反转它。。
- 空间复杂度：`O(n)`，由于递归，在最坏的情况下，`O(h)`函数调用将被放置在堆上，其中h是树的高度。因为在 `h ∈ O(n)`，所以空间复杂度是`O(n)`。

#### 方法二：迭代

或者，我们可以以类似于广度优先搜索的方式迭代地解决问题

**算法**

我们的想法是，我们需要交换树中所有节点的左右子节点。因此，我们创建一个队列来存储其左右孩子尚未交换的节点。最初，只有根位于队列中。只要队列不为空，就从队列中取出下一个节点，交换其子节点，然后将子节点添加到队列中。空节点不添加到队列中。最终，队列将为空并且所有子项都交换，我们返回原始根。

- 使用队列

```java
public TreeNode invertTree(TreeNode root) {
    if (root == null) return null;
    // LinkedList实现了集合框架的Queue接口
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root); // 加入元素
    while (!queue.isEmpty()) {
      // 获取并移出元素
      TreeNode current = queue.poll();

      //交换左右子树
      TreeNode temp = current.left;
      current.left = current.right;
      current.right = temp;

      //左子树不为空，将左子树入栈
      if (current.left != null) queue.add(current.left);
      //右子树不为空，将右子树入栈
      if (current.right != null) queue.add(current.right);
    }
    return root;
}
```

- 使用栈

```java
public TreeNode invertTree(TreeNode root) {
    if (root == null) return null;
  
    Stack<TreeNode> stack = new Stack<>();
    stack.push(root);//先将根节点压入堆栈
    while (stack.size() > 0) {
      //根据栈的先进后出操作，获取栈中最后一个元素，即最先入栈的元素
      TreeNode temp = stack.lastElement();
      stack.pop();//弹出栈顶元素

      //交换左右子树
      TreeNode tempLeft = temp.left;
      temp.left = temp.right;
      temp.right = tempLeft;

      //左子树不为空，将左子树入栈
      if (temp.left != null) {
        stack.push(temp.left);
      }
      //右子树不为空，将右子树入栈
      if (temp.right != null) {
        stack.push(temp.right);
      }
    }
    return root;
}
```

**复杂度分析**

- 时间复杂度：O(n)，由于树中的每个节点仅被访问 / 添加到队列一次，因此时间复杂度为O(n)，其中n是树中的节点数。
- 空间复杂度：O(n)，因为在最坏的情况下，队列将包含二叉树的一个级别中的所有节点。对于完整的二叉树，叶级别为⌈*n*/2⌉=*O*(*n*) 。

Analysis written by: @noran

### 注意

翻译的可能不够准确，请在下面的评论中批评指正。

