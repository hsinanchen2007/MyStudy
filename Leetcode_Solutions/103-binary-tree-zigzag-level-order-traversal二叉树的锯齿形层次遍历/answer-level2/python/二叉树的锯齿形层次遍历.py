#### 方法一：BFS（广度优先遍历）

**思路**

最直观的方法是 BFS，逐层遍历树。

BFS 在每层的默认顺序是从左到右，因此需要调整 BFS 算法以生成锯齿序列。

> 最关键的是使用双端队列遍历，可以在队列的任一端插入元素。

如果需要 **FIFO** （先进先出）的顺序，则将新元素添加到队列尾部，后插入的元素就可以排在后面。如果需要 **FILO** （先进后出）的顺序，则将新元素添加到队列首部，后插入的元素就可以排在前面。

![](https://pic.leetcode-cn.com/Figures/103/103_BFS.png)

**算法**

实现 BFS 的几种算法。

- 使用两层嵌套循环。外层循环迭代树的层级，内层循环迭代每层上的节点。

- 也可以使用一层循环实现 BFS。将要访问的节点添加到队列中，使用 **分隔符**（例如：空节点）把不同层的节点分隔开。分隔符表示一层结束和新一层开始。

这里采用第二种方法。在此算法的基础上，借助双端队列实现锯齿形顺序。在每一层，使用一个空的双端队列保存该层所有的节点。根据每一层的访问顺序，即从左到右或从右到左，决定从双端队列的哪一端插入节点。

![](https://pic.leetcode-cn.com/Figures/103/103_deque.png)

- 实现从左到右的遍历顺序（FIFO）。将元素添加到队列尾部，保证后添加的节点后被访问。从上图中可以看出，输入序列 `[1, 2, 3, 4, 5]`，按照 FIFO 顺序得到输出序列为 `[1, 2, 3, 4, 5]`。

- 实现从右到左的遍历顺序（FILO）。将元素添加到队列头部，保证后添加的节点先被访问。输入序列 `[1, 2, 3, 4, 5]`，按照 FILO 顺序得到输出序列为 `[5, 4, 3, 2, 1]`。

```python [solution1-Python]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        level_list = deque()
        if root is None:
            return []
        # start with the level 0 with a delimiter
        node_queue = deque([root, None])
        is_order_left = True

        while len(node_queue) > 0:
            curr_node = node_queue.popleft()

            if curr_node:
                if is_order_left:
                    level_list.append(curr_node.val)
                else:
                    level_list.appendleft(curr_node.val)

                if curr_node.left:
                    node_queue.append(curr_node.left)
                if curr_node.right:
                    node_queue.append(curr_node.right)
            else:
                # we finish one level
                ret.append(level_list)
                # add a delimiter to mark the level
                if len(node_queue) > 0:
                    node_queue.append(None)

                # prepare for the next level
                level_list = deque()
                is_order_left = not is_order_left

        return ret
```

```java [solution1-Java]
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
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    if (root == null) {
      return new ArrayList<List<Integer>>();
    }

    List<List<Integer>> results = new ArrayList<List<Integer>>();

    // add the root element with a delimiter to kick off the BFS loop
    LinkedList<TreeNode> node_queue = new LinkedList<TreeNode>();
    node_queue.addLast(root);
    node_queue.addLast(null);

    LinkedList<Integer> level_list = new LinkedList<Integer>();
    boolean is_order_left = true;

    while (node_queue.size() > 0) {
      TreeNode curr_node = node_queue.pollFirst();
      if (curr_node != null) {
        if (is_order_left)
          level_list.addLast(curr_node.val);
        else
          level_list.addFirst(curr_node.val);

        if (curr_node.left != null)
          node_queue.addLast(curr_node.left);
        if (curr_node.right != null)
          node_queue.addLast(curr_node.right);

      } else {
        // we finish the scan of one level
        results.add(level_list);
        level_list = new LinkedList<Integer>();
        // prepare for the next level
        if (node_queue.size() > 0)
          node_queue.addLast(null);
        is_order_left = !is_order_left;
      }
    }
    return results;
  }
}
```

注意：一种替代做法是，实现标准的 BFS 算法，得到每层节点从左到右的遍历顺序。然后按照要求 **翻转** 某些层节点的顺序，得到锯齿形的遍历结果。

**复杂度分析**

- 时间复杂度：$\mathcal{O}(N)$，其中 $N$ 是树中节点的数量。

    - 每个节点仅访问一次。

    - 双端队列的插入操作为常数时间。如果使用数组或 list，头部插入需要 $\mathcal{O}(K)$ 的时间，其中 $K$ 是数组或 list 的长度。 

- 空间复杂度：$\mathcal{O}(N)$，其中 $N$ 是树中节点的数量。

    - 除了输出数组，主要的内存开销是双端队列。

    - 任何时刻，双端队列中最多只存储两层节点。因此双端队列的大小不超过 $2 \cdot L$，其中 $L$ 是一层的最大节点数。包含最多节点的层可能是完全二叉树的叶节点层，大约有 $L = \frac{N}{2}$ 个节点。因此最坏情况下，空间复杂度为 $2 \cdot \frac{N}{2} = N$。

#### 方法二：DFS （深度优先遍历）

**思路**

也可以使用 *DFS* 实现 *BFS* 的遍历顺序。

> 在 DFS 遍历期间，将结果保存在按层数索引的全局数组中。即元素 `array[level]` 存储同一层的所有节点。然后在 DFS 的每一步更新全局数组。

![](https://pic.leetcode-cn.com/Figures/103/103_DFS.png)

与改进的 BFS 算法类似，使用双端队列保存同一层的所有节点，并交替插入方向（从首部插入或从尾部插入）得到需要的输出顺序。

**算法**

使用递归实现 DFS 算法。定义一个递归方法 `DFS(node, level)`，方法参数为当前节点 `node` 和指定层数 `level`。该方法共执行三个步骤：

- 如果是第一次访问该层的节点，即该层的双端队列不存在。那么创建一个双端队列，并添加该节点到队列中。

- 如果当前层的双端队列已存在，根据顺序，将当前节点插入队列头部或尾部。

- 最后，为每个节点调用该递归方法。

```python [solution2-Python]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []

        results = []
        def dfs(node, level):
            if level >= len(results):
                results.append(deque([node.val]))
            else:
                if level % 2 == 0:
                    results[level].append(node.val)
                else:
                    results[level].appendleft(node.val)

            for next_node in [node.left, node.right]:
                if next_node is not None:
                    dfs(next_node, level+1)

        # normal level order traversal with DFS
        dfs(root, 0)

        return results
```

```java [solution2-Java]
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
  protected void DFS(TreeNode node, int level, List<List<Integer>> results) {
    if (level >= results.size()) {
      LinkedList<Integer> newLevel = new LinkedList<Integer>();
      newLevel.add(node.val);
      results.add(newLevel);
    } else {
      if (level % 2 == 0)
        results.get(level).add(node.val);
      else
        results.get(level).add(0, node.val);
    }

    if (node.left != null) DFS(node.left, level + 1, results);
    if (node.right != null) DFS(node.right, level + 1, results);
  }

  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    if (root == null) {
      return new ArrayList<List<Integer>>();
    }
    List<List<Integer>> results = new ArrayList<List<Integer>>();
    DFS(root, 0, results);
    return results;
  }
}
```

也可以通过 **迭代** 实现 DFS 遍历。

**复杂度分析**

- 时间复杂度：$\mathcal{O}(N)$，其中$N$ 是树中节点的数量。

    - 与 BFS 相同，每个节点只访问一次。

- 空间复杂度：$\mathcal{O}(H)$，其中 $H$ 是树的高度。例如：包含 $N$ 个节点的树，高度大约为 $\log_2{N}$。

    - 与 BFS 不同，在 DFS 中不需要维护双端队列。
    
    - 方法递归调用会产生额外的内存消耗。方法 `DFS(node, level)` 的调用堆栈大小刚好等于节点所在层数。因此 DFS 的空间复杂度为 $\mathcal{O}(\log_2{N})$，这比 BFS 好很多。