####  概述
这是教科书上一个经典问题，用来测试一个人的数据结构知识。因此，是不可以用任何内置的 HashSet 数据结构来解决此问题。

为了实现 HashSet 数据结构，有两个关键的问题，即哈希函数和冲突处理。

- 哈希函数：目的是分配一个地址存储值。理想情况下，每个值都应该有一个对应唯一的散列值。
- 冲突处理：哈希函数的本质就是从 A 映射到 B。但是多个 A 值可能映射到相同的 B。这就是碰撞。因此，我们需要有对应的策略来解决碰撞。总的来说，有以下几种策略解决冲突：
	- 单独链接法：对于相同的散列值，我们将它们放到一个桶中，每个桶是相互独立的。
	- 开放地址法：每当有碰撞， 则根据我们探查的策略找到一个空的槽为止。
	- 双散列法：使用两个哈希函数计算散列值，选择碰撞更少的地址。

在本文中，我们使用单独链接法，来看看它是如何工作的。
- 从本质上讲，HashSet 的存储空间相当于连续内存数组。这个数组中的每个元素相当于一个桶。
- 给定一个值，我们首先通过哈希函数生成对应的散列值来定位桶的位置。
- 一旦找到桶的位置，则在该桶上做相对应的操作，如 `add`，`remove`，`contains`。


####  方法一：单独链表法
哈希函数的共同特点是使用模运算符。$\text{hash} = \text{value} \mod \text{base}$。其中，$\text{base}$ 将决定 HashSet 中的桶数。

从理论上讲，桶越多（因此空间会越大）越不太可能发生碰撞。$\text{base}$ 的选择是空间和碰撞之间的权衡。

此外，使用质数作为 $\text{base}$ 是一个明智的选择。例如 $769$，可以减少潜在的碰撞。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1LzcwNV9saW5rZWRfbGlzdC5wbmc?x-oss-process=image/format,png)

对于桶的设计，我们有几种选择，可以使用数组来存储桶的所有值。然而数组的一个缺点是需要 $\mathcal{O}(N)$ 的时间复杂度进行插入和删除，而不是 $\mathcal{O}(1)$。

因为任何的更新操作，我们首先是需要扫描整个桶为了避免重复。选择链表来存储桶的所有值是更好的选择，插入和删除具有常数的时间复杂度。

**算法：**

正如我们在上面讨论的，这里将采用 `LinkedList` 实现 HashSet 中的桶。

对于每个功能 `add`，`remove`，`contains`，我们首先生成桶的散列值，操作相对应的桶。

```python [solution1-Python]
class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keyRange = 769
        self.bucketArray = [Bucket() for i in range(self.keyRange)]

    def _hash(self, key):
        return key % self.keyRange

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        bucketIndex = self._hash(key)
        self.bucketArray[bucketIndex].insert(key)

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        bucketIndex = self._hash(key)
        self.bucketArray[bucketIndex].delete(key)

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        bucketIndex = self._hash(key)
        return self.bucketArray[bucketIndex].exists(key)


class Node:
    def __init__(self, value, nextNode=None):
        self.value = value
        self.next = nextNode

class Bucket:
    def __init__(self):
        # a pseudo head
        self.head = Node(0)

    def insert(self, newValue):
        # if not existed, add the new element to the head.
        if not self.exists(newValue):
            newNode = Node(newValue, self.head.next)
            # set the new head.
            self.head.next = newNode

    def delete(self, value):
        prev = self.head
        curr = self.head.next
        while curr is not None:
            if curr.value == value:
                # remove the current node
                prev.next = curr.next
                return
            prev = curr
            curr = curr.next

    def exists(self, value):
        curr = self.head.next
        while curr is not None:
            if curr.value == value:
                # value existed already, do nothing
                return True
            curr = curr.next
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```

```java [solution1-Java]
class MyHashSet {
  private Bucket[] bucketArray;
  private int keyRange;

  /** Initialize your data structure here. */
  public MyHashSet() {
    this.keyRange = 769;
    this.bucketArray = new Bucket[this.keyRange];
    for (int i = 0; i < this.keyRange; ++i)
      this.bucketArray[i] = new Bucket();
  }

  protected int _hash(int key) {
    return (key % this.keyRange);
  }

  public void add(int key) {
    int bucketIndex = this._hash(key);
    this.bucketArray[bucketIndex].insert(key);
  }

  public void remove(int key) {
    int bucketIndex = this._hash(key);
    this.bucketArray[bucketIndex].delete(key);
  }

  /** Returns true if this set contains the specified element */
  public boolean contains(int key) {
    int bucketIndex = this._hash(key);
    return this.bucketArray[bucketIndex].exists(key);
  }
}


class Bucket {
  private LinkedList<Integer> container;

  public Bucket() {
    container = new LinkedList<Integer>();
  }

  public void insert(Integer key) {
    int index = this.container.indexOf(key);
    if (index == -1) {
      this.container.addFirst(key);
    }
  }

  public void delete(Integer key) {
    this.container.remove(key);
  }

  public boolean exists(Integer key) {
    int index = this.container.indexOf(key);
    return (index != -1);
  }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```


**复杂度分析**

* 时间复杂度：$\mathcal{O}(\frac{N}{K})$。其中 $N$ 指的是所有可能值数量，$K$ 指的是预定义的桶数，也就是 `769`。
	*  假设值是平均分布的，因此可以考虑桶的平均大小是 $\frac{N}{K}$。
	* 对于每个操作，在最坏的情况下，我们需要扫描整个桶，因此时间复杂度是 $\mathcal{O}(\frac{N}{K})$。
* 空间复杂度：$\mathcal{O}(K+M)$，其中 $K$ 指的是预定义的桶数，$M$ 指的是已经插入到 HashSet 中值的数量。


####  方法二：使用二叉搜索树作为桶
在上述的方法中，有一个缺点，我们需要扫描整个桶才能验证一个值是否已经在桶中（即查找操作）。

我们可以将桶作为一个排序列表，可以使用二分搜索使查找操作的时间复杂度是 $\mathcal{O}(\log{N})$，优于 上面方法中的 $\mathcal{O}({N})$。

另一方面，如果使用排序列表等连续空间的数组来实现，则会产生线性时间复杂度的更新操作，因此需要其他的方式。

有数据结构具有 $\mathcal{O}(\log{N})$ 时间复杂度的查找，删除，插入操作吗？

当然有，就是二叉搜索树。二叉搜索树的特性使得我们能够优化时间复杂度。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1LzcwNV9CU1QucG5n?x-oss-process=image/format,png)
因此现在是使用标准的二叉搜索树作为 HashSet 的桶来实现。

**算法：**

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1L3NsaWRlXzAucG5n?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1L3NsaWRlXzEucG5n?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1L3NsaWRlXzIucG5n?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1L3NsaWRlXzMucG5n?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNzA1L3NsaWRlXzQucG5n?x-oss-process=image/format,png)>

实际上，我们将二叉搜索树的每个操作作为 LeetCode 的独立问题，如下：
- [700. Search in a BST](https://leetcode-cn.com/problems/search-in-a-binary-search-tree/)
- [701. Insert in a BST](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)
- [450. Delete in a BST](https://leetcode-cn.com/problems/delete-node-in-a-bst/)

可以试着去练习，然后结合在一起全面实现二叉搜索树。

```python [solution2-Python]
class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keyRange = 769
        self.bucketArray = [Bucket() for i in range(self.keyRange)]

    def _hash(self, key) -> int:
        return key % self.keyRange

    def add(self, key: int) -> None:
        bucketIndex = self._hash(key)
        self.bucketArray[bucketIndex].insert(key)

    def remove(self, key: int) -> None:
        """
        :type key: int
        :rtype: None
        """
        bucketIndex = self._hash(key)
        self.bucketArray[bucketIndex].delete(key)

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        bucketIndex = self._hash(key)
        return self.bucketArray[bucketIndex].exists(key)

class Bucket:
    def __init__(self):
        self.tree = BSTree()

    def insert(self, value):
        self.tree.root = self.tree.insertIntoBST(self.tree.root, value)

    def delete(self, value):
        self.tree.root = self.tree.deleteNode(self.tree.root, value)

    def exists(self, value):
        return (self.tree.searchBST(self.tree.root, value) is not None)

class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

class BSTree:
    def __init__(self):
        self.root = None

    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None or val == root.val:
            return root

        return self.searchBST(root.left, val) if val < root.val \
            else self.searchBST(root.right, val)

    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)

        if val > root.val:
            # insert into the right subtree
            root.right = self.insertIntoBST(root.right, val)
        elif val == root.val:
            return root
        else:
            # insert into the left subtree
            root.left = self.insertIntoBST(root.left, val)
        return root

    def successor(self, root):
        """
        One step right and then always left
        """
        root = root.right
        while root.left:
            root = root.left
        return root.val

    def predecessor(self, root):
        """
        One step left and then always right
        """
        root = root.left
        while root.right:
            root = root.right
        return root.val

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None

        # delete from the right subtree
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        # delete from the left subtree
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        # delete the current node
        else:
            # the node is a leaf
            if not (root.left or root.right):
                root = None
            # the node is not a leaf and has a right child
            elif root.right:
                root.val = self.successor(root)
                root.right = self.deleteNode(root.right, root.val)
            # the node is not a leaf, has no right child, and has a left child
            else:
                root.val = self.predecessor(root)
                root.left = self.deleteNode(root.left, root.val)

        return root

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
```

```java [solution2-Java]
class MyHashSet {
  private Bucket[] bucketArray;
  private int keyRange;

  /** Initialize your data structure here. */
  public MyHashSet() {
    this.keyRange = 769;
    this.bucketArray = new Bucket[this.keyRange];
    for (int i = 0; i < this.keyRange; ++i)
      this.bucketArray[i] = new Bucket();
  }

  protected int _hash(int key) {
    return (key % this.keyRange);
  }

  public void add(int key) {
    int bucketIndex = this._hash(key);
    this.bucketArray[bucketIndex].insert(key);
  }

  public void remove(int key) {
    int bucketIndex = this._hash(key);
    this.bucketArray[bucketIndex].delete(key);
  }

  /** Returns true if this set contains the specified element */
  public boolean contains(int key) {
    int bucketIndex = this._hash(key);
    return this.bucketArray[bucketIndex].exists(key);
  }
}


class Bucket {
  private BSTree tree;

  public Bucket() {
    tree = new BSTree();
  }

  public void insert(Integer key) {
    this.tree.root = this.tree.insertIntoBST(this.tree.root, key);
  }

  public void delete(Integer key) {
    this.tree.root = this.tree.deleteNode(this.tree.root, key);
  }

  public boolean exists(Integer key) {
    TreeNode node = this.tree.searchBST(this.tree.root, key);
    return (node != null);
  }
}

public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}

class BSTree {
  TreeNode root = null;

  public TreeNode searchBST(TreeNode root, int val) {
    if (root == null || val == root.val)
      return root;

    return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
  }

  public TreeNode insertIntoBST(TreeNode root, int val) {
    if (root == null)
      return new TreeNode(val);

    if (val > root.val)
      // insert into the right subtree
      root.right = insertIntoBST(root.right, val);
    else if (val == root.val)
      // skip the insertion
      return root;
    else
      // insert into the left subtree
      root.left = insertIntoBST(root.left, val);
    return root;
  }

  /*
   * One step right and then always left
   */
  public int successor(TreeNode root) {
    root = root.right;
    while (root.left != null)
      root = root.left;
    return root.val;
  }

  /*
   * One step left and then always right
   */
  public int predecessor(TreeNode root) {
    root = root.left;
    while (root.right != null)
      root = root.right;
    return root.val;
  }

  public TreeNode deleteNode(TreeNode root, int key) {
    if (root == null)
      return null;

    // delete from the right subtree
    if (key > root.val)
      root.right = deleteNode(root.right, key);
    // delete from the left subtree
    else if (key < root.val)
      root.left = deleteNode(root.left, key);
    // delete the current node
    else {
      // the node is a leaf
      if (root.left == null && root.right == null)
        root = null;
      // the node is not a leaf and has a right child
      else if (root.right != null) {
        root.val = successor(root);
        root.right = deleteNode(root.right, root.val);
      }
      // the node is not a leaf, has no right child, and has a left child
      else {
        root.val = predecessor(root);
        root.left = deleteNode(root.left, root.val);
      }
    }
    return root;
  }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\frac{N}{K})$。其中 $N$ 指的是所有可能值数量，$K$ 指的是预定义的桶数，也就是 `769`。
	*  假设值是平均分布的，因此可以考虑桶的平均大小是 $\frac{N}{K}$。
	* 当我们遍历二叉搜索树时，使用二分查找，最后每个操作的时间复杂度是 $\mathcal{O}(\log{\frac{N}{K}})$。
* 空间复杂度：$\mathcal{O}(K+M)$，其中 $K$ 指的是预定义的桶数，$M$ 指的是已经插入到 HashSet 中值的数量。