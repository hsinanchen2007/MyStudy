####  方法一：对数组进行排序
让我们从直截了当但却不是最优的解决方案开始。这个解决方案具有线性的时间和空间复杂性。

我们直到 BST 的中序遍历是升序序列。下面展示了如何计算中序遍历。

```java [inorder-Java]
public void inorder(TreeNode root, List<Integer> nums) {
  if (root == null) return;
  inorder(root.left, nums);
  nums.add(root.val);
  inorder(root.right, nums);
}
```

```python [inorder-Python]
def inorder(r: TreeNode) -> List[int]:
    return inorder(r.left) + [r.val] + inorder(r.right) if r else []
```

这里被交换了两个节点，因此中序遍历是一个几乎排好序的数组，其中有两个元素被交换。识别排序数组中两个交换元素是可以在线性时间内解决的经典问题。

```java [findtwoswapped-Java]
public int[] findTwoSwapped(List<Integer> nums) {
  int n = nums.size();
  int x = -1, y = -1;
  for(int i = 0; i < n - 1; ++i) {
    if (nums.get(i + 1) < nums.get(i)) {
      y = nums.get(i + 1);
      // first swap occurence
      if (x == -1) x = nums.get(i);
      // second swap occurence
      else break;
    }
  }
  return new int[]{x, y};
}
```

```python [findtwoswapped-Python]
def find_two_swapped(nums: List[int]) -> (int, int):
    n = len(nums)
    x = y = -1
    for i in range(n - 1):
        if nums[i + 1] < nums[i]:
            y = nums[i + 1]
            # first swap occurence
            if x == -1:     
                x = nums[i]
            # second swap occurence
            else:           
                break
    return x, y
```

当已知两个交换节点，再次遍历树，交换该节点的值。

**算法：**

1. 按中序遍历树。遍历后的数组应该是几乎排序的列表，其中只有两个元素被交换。
2. 在线性时间内确定几乎排序数组中的两个交换元素 `x` 和 `y`。
3. 再次遍历树，将值 `x` 的节点改为 `y`，将值 `y` 的节点改为 `x`。

```python [solution1-Python]
class Solution:
    def recoverTree(self, root: TreeNode):
        """
        :rtype: void Do not return anything, modify root in-place instead.
        """
        def inorder(r: TreeNode) -> List[int]:
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
        
        def find_two_swapped(nums: List[int]) -> (int, int):
            n = len(nums)
            x = y = -1
            for i in range(n - 1):
                if nums[i + 1] < nums[i]:
                    y = nums[i + 1]
                    # first swap occurence
                    if x == -1:     
                        x = nums[i]
                    # second swap occurence
                    else:           
                        break
            return x, y
        
        def recover(r: TreeNode, count: int):
            if r:
                if r.val == x or r.val == y:
                    r.val = y if r.val == x else x
                    count -= 1
                    if count == 0:
                        return      
                recover(r.left, count)
                recover(r.right, count)
            
        nums = inorder(root)
        x, y = find_two_swapped(nums)
        recover(root, 2)
```

```java [solution1-Java]
class Solution {
  public void inorder(TreeNode root, List<Integer> nums) {
    if (root == null) return;
    inorder(root.left, nums);
    nums.add(root.val);
    inorder(root.right, nums);
  }

  public int[] findTwoSwapped(List<Integer> nums) {
    int n = nums.size();
    int x = -1, y = -1;
    for(int i = 0; i < n - 1; ++i) {
      if (nums.get(i + 1) < nums.get(i)) {
        y = nums.get(i + 1);
        // first swap occurence
        if (x == -1) x = nums.get(i);
        // second swap occurence
        else break;
      }
    }
    return new int[]{x, y};
  }

  public void recover(TreeNode r, int count, int x, int y) {
    if (r != null) {
      if (r.val == x || r.val == y) {
        r.val = r.val == x ? y : x;
        if (--count == 0) return;
      }
      recover(r.left, count, x, y);
      recover(r.right, count, x, y);
    }
  }

  public void recoverTree(TreeNode root) {
    List<Integer> nums = new ArrayList();
    inorder(root, nums);
    int[] swapped = findTwoSwapped(nums);
    recover(root, 2, swapped[0], swapped[1]);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。中序遍历需要 $\mathcal{O}(N)$ 的时间，判断两个交换节点：在最好的情况下是 $\mathcal{O}(1)$，在最坏的情况下是 $\mathcal{O}(N)$。
* 空间复杂度：$\mathcal{O}(N)$，我们用 `nums` 数组保存了树的中序遍历列表。


####  接下来是什么：
在方法一中，我们讨论了这个难题的三个简单子问题：

1. 构造中序遍历序列。
2. 在几乎排序的数组中查找两个交换的元素。
3. 在数中交换两个节点的值。

现在我们再讨论三种方法，基本上都有：

- 合并步骤一和步骤二，即在中序遍历确定交换的节点。
- 交换节点值。

以下方法的区别在于实现中序遍历的方法。

- 方法二：迭代
- 方法三：递归
- 方法四：Morris 算法

这里的迭代和递归只进行少于一次的遍历，它们都需要高达 $\mathcal{O}(H)$ 的空间来保存堆栈，其中 $H$ 指的是树的高度。

Morris 算法是遍历两次的方法，但它是一个常数级空间的方法。


####  方法二：迭代中序遍历
**算法：**

在这里，我们通过迭代构造中序遍历，并在一次遍历中找到交换的节点。

迭代顺序很简单：尽可能的向左走，然后向右走一步，重复一直到结束。

若要找到交换的节点，就记录中序遍历中的最后一个节点 `pred`（即当前节点的前置节点），并与当前节点的值进行比较。如果当前节点的值小于前置节点 `pred` 的值，说明该节点是交换节点之一。

交换的节点只有两个，因此在确定了第二个交换节点以后，可以终止遍历。

这样，就可以直接获取节点（而不仅仅是它们的值），从而实现 $\mathcal{O}(1)$ 的交换时间，大大减少了步骤 3 所需的时间。 

<![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF8xLnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF8yLnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF8zLnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF80LnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF81LnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF82LnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF83LnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF84LnBuZw?x-oss-process=image/format,png),![image.png](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc2xpZF85LnBuZw?x-oss-process=image/format,png)>

[在 java 中用 `ArrayDeque` 代替栈。](https://docs.oracle.com/javase/8/docs/api/java/util/Stack.html)


```python [solution2-Python]
class Solution:
    def recoverTree(self, root: TreeNode):
        """
        :rtype: void Do not return anything, modify root in-place instead.
        """
        stack = []
        x = y = pred = None
        
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pred and root.val < pred.val:
                y = root
                if x is None:
                    x = pred 
                else:
                    break
            pred = root
            root = root.right

        x.val, y.val = y.val, x.val
```

```java [solution2-Java]
class Solution {
  public void swap(TreeNode a, TreeNode b) {
    int tmp = a.val;
    a.val = b.val;
    b.val = tmp;
  }

  public void recoverTree(TreeNode root) {
    Deque<TreeNode> stack = new ArrayDeque();
    TreeNode x = null, y = null, pred = null;

    while (!stack.isEmpty() || root != null) {
      while (root != null) {
        stack.add(root);
        root = root.left;
      }
      root = stack.removeLast();
      if (pred != null && root.val < pred.val) {
        y = root;
        if (x == null) x = pred;
        else break;
      }
      pred = root;
      root = root.right;
    }

    swap(x, y);
  }
}
```

**复杂度分析**

* 时间复杂度：最好的情况下是 $\mathcal{O}(1)$；最坏的情况下是交换节点之一是最右边的叶节点时，此时是 $\mathcal{O}(N)$。
* 空间复杂度：最大是 $\mathcal{O}(H)$ 来维持栈的大小，其中 $H$ 指的是树的高度。


####  方法三：递归中序遍历
**算法：**

方法二的迭代可以转换为递归方式。

递归中序遍历很简单：遵循 `Left->Node->Right` 方向，即对左子节点进行递归调用，然后判断该节点是否被交换，然后对右子节点执行递归调用。

```python [solution3-Python]
class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        def find_two_swapped(root: TreeNode):
            nonlocal x, y, pred
            if root is None:
                return
            
            find_two_swapped(root.left)
            if pred and root.val < pred.val:
                y = root
                # first swap occurence
                if x is None:
                    x = pred 
                # second swap occurence
                else:
                    return
            pred = root
            find_two_swapped(root.right)
        
        x = y = pred = None
        find_two_swapped(root)
        x.val, y.val = y.val, x.val
```

```java [solution3-Java]
class Solution {
  TreeNode x = null, y = null, pred = null;

  public void swap(TreeNode a, TreeNode b) {
    int tmp = a.val;
    a.val = b.val;
    b.val = tmp;
  }

  public void findTwoSwapped(TreeNode root) {
    if (root == null) return;
    findTwoSwapped(root.left);
    if (pred != null && root.val < pred.val) {
      y = root;
      if (x == null) x = pred;
      else return;
    }
    pred = root;
    findTwoSwapped(root.right);
  }

  public void recoverTree(TreeNode root) {
    findTwoSwapped(root);
    swap(x, y);
  }
}
```

**复杂度分析**

* 时间复杂度：最好的情况下是 $\mathcal{O}(1)$；最坏的情况下是交换节点之一是最右边的叶节点时，此时是 $\mathcal{O}(N)$。
* 空间复杂度：最大是 $\mathcal{O}(H)$ 来维持递归调用堆栈的大小，其中 $H$ 指的是树的高度。


####  方法四：Morris 中序遍历
**算法：**

我们已经讨论了迭代和递归中序遍历，但是这两种遍历尽管使用了 $\mathcal{O}(H)$ 的空间去存储栈空间，但是都有较大的时间复杂度。我们可以通过牺牲性能来届生空间。

Morris 的遍历思想很简单：只遍历树而不是用空间。

怎么能够做到呢？在每个节点上，你必须决定下一个遍历的方向：遍历左子树或者右子树。如果不适用额外的空间，怎么指的左子树已经遍历完成了呢？

Morris 算法的思想是在节点和它的直接前驱之间设置一个临时的链接：`predecessor.right = root`，从该节点开始，找到它的直接前驱并验证是否存在链接。

- 如果没有链接，设置连接并走向左子树。
- 如果有连接，断开连接并走向右子树。

这里有一个小问题要处理：如果该节点没有左孩子，即没有左子树，则我们直接走向右子树。

<![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc18xLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc18yLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc18zLnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc180LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc181LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc182LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc183LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc184LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc185LnBuZw?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc18xMC5wbmc?x-oss-process=image/format,png),![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvOTkvOTlfc18xMS5wbmc?x-oss-process=image/format,png)>

```python [solution4-Python]
class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        # predecessor is a Morris predecessor. 
        # In the 'loop' cases it could be equal to the node itself predecessor == root.
        # pred is a 'true' predecessor, 
        # the previous node in the inorder traversal.
        x = y = predecessor = pred = None
        
        while root:
            # If there is a left child
            # then compute the predecessor.
            # If there is no link predecessor.right = root --> set it.
            # If there is a link predecessor.right = root --> break it.
            if root.left:       
                # Predecessor node is one step left 
                # and then right till you can.
                predecessor = root.left
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right
 
                # set link predecessor.right = root
                # and go to explore left subtree
                if predecessor.right is None:
                    predecessor.right = root
                    root = root.left
                # break link predecessor.right = root
                # link is broken : time to change subtree and go right
                else:
                    # check for the swapped nodes
                    if pred and root.val < pred.val:
                        y = root
                        if x is None:
                            x = pred 
                    pred = root
                    
                    predecessor.right = None
                    root = root.right
            # If there is no left child
            # then just go right.
            else:
                # check for the swapped nodes
                if pred and root.val < pred.val:
                    y = root
                    if x is None:
                        x = pred 
                pred = root
                
                root = root.right
        
        x.val, y.val = y.val, x.val
```

```java [solution4-Java]
class Solution {
  public void swap(TreeNode a, TreeNode b) {
    int tmp = a.val;
    a.val = b.val;
    b.val = tmp;
  }

  public void recoverTree(TreeNode root) {
    // predecessor is a Morris predecessor. 
    // In the 'loop' cases it could be equal to the node itself predecessor == root.
    // pred is a 'true' predecessor, 
    // the previous node in the inorder traversal.
    TreeNode x = null, y = null, pred = null, predecessor = null;

    while (root != null) {
      // If there is a left child
      // then compute the predecessor.
      // If there is no link predecessor.right = root --> set it.
      // If there is a link predecessor.right = root --> break it.
      if (root.left != null) {
        // Predecessor node is one step left 
        // and then right till you can.
        predecessor = root.left;
        while (predecessor.right != null && predecessor.right != root)
          predecessor = predecessor.right;

        // set link predecessor.right = root
        // and go to explore left subtree
        if (predecessor.right == null) {
          predecessor.right = root;
          root = root.left;
        }
        // break link predecessor.right = root
        // link is broken : time to change subtree and go right
        else {
          // check for the swapped nodes
          if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null) x = pred;
          }
          pred = root;

          predecessor.right = null;
          root = root.right;
        }
      }
      // If there is no left child
      // then just go right.
      else {
        // check for the swapped nodes
        if (pred != null && root.val < pred.val) {
          y = root;
          if (x == null) x = pred;
        }
        pred = root;

        root = root.right;
      }
    }
    swap(x, y);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$，我们访问每个节点两次。
* 空间复杂度：$\mathcal{O}(1)$。