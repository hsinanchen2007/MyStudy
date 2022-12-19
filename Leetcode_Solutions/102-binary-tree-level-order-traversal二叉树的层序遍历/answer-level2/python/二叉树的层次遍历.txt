#### 如何遍历一棵树

有两种通用的遍历树的策略：

* *深度优先搜索*（`DFS`）

  在这个策略中，我们采用`深度`作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。

  深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为`先序遍历`，`中序遍历`和`后序遍历`。

* *宽度优先搜索*（`BFS`）

  我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。

下图中的顶点按照访问的顺序编号，按照 `1-2-3-4-5` 的顺序来比较不同的策略。

![102.png](https://pic.leetcode-cn.com/b61ff2d47852e4264f5dfe0a5b00101bdeca2b0ba216aa83ca3cb6fac42ebb84-102.png){:width="450px"}
{:align=center}

本问题就是用宽度优先搜索遍历来划分层次：`[[1], [2, 3], [4, 5]]`。

#### 方法 1：递归

**算法**

最简单的解法就是递归，首先确认树非空，然后调用递归函数 `helper(node, level)`，参数是当前节点和节点的层次。程序过程如下：

* 输出列表称为 `levels`，当前最高层数就是列表的长度 `len(levels)`。比较访问节点所在的层次 `level` 和当前最高层次 `len(levels)` 的大小，如果前者更大就向 `levels` 添加一个空列表。
* 将当前节点插入到对应层的列表 `levels[level]` 中。
* 递归非空的孩子节点：`helper(node.left / node.right, level + 1)`。

**实现**

<![image.png](https://pic.leetcode-cn.com/39ef8ca2950dc33944751cfaa9c47941936990231317806b511fef34d769ec49-image.png),![image.png](https://pic.leetcode-cn.com/b0328b416a214e24a82d427139a12c93856cf0f13efbd076653176b478728539-image.png),![image.png](https://pic.leetcode-cn.com/cb8b1afc60b27d0b2b45b1df9252a4d27c3abf7d306bcf2d8e14369bd93ebe17-image.png),![image.png](https://pic.leetcode-cn.com/408ce92d5f688522cff57accc4a5f93a81593d31258e3010791d433c3437d4a9-image.png),![image.png](https://pic.leetcode-cn.com/a7f338b20a28aaab27b2b29d59cae33d064b8edf139a346fb71bf11466b935ab-image.png),![image.png](https://pic.leetcode-cn.com/a1a01a56651aa2b145be08633b61f5e22a786284297f68f4bcdf5cea3e53765f-image.png),![image.png](https://pic.leetcode-cn.com/832737f3f038d248aed00cf717d5ad19ab661be22fada26dace59f1ada7ea5fb-image.png),![image.png](https://pic.leetcode-cn.com/4099e5c7024a12809f130d5a3d1d210511b955cdd76f017ada79a60538801238-image.png),![image.png](https://pic.leetcode-cn.com/d9ad3c644af09e263389548e23ad3fa0fab61dc301e65173ca188922649ec6f6-image.png),![image.png](https://pic.leetcode-cn.com/06de2e2964d52f1ba37fd65abd73f39b8d879fcdcba1d9b964c836504658c899-image.png),![image.png](https://pic.leetcode-cn.com/e948aa7988735f6f205b22853476f558e931e11e0d57858ef888f2a3e9b845d1-image.png),![image.png](https://pic.leetcode-cn.com/768d096b5d1f0ba9c58256a2b439d9c066f341a90f690c27372c86fbf03bb22f-image.png),![image.png](https://pic.leetcode-cn.com/a6db53a26528d771da31141dfd8dfad807b749fcfa238c3043e398b4a85b4a1e-image.png),![image.png](https://pic.leetcode-cn.com/0cac58e024b0e785172109a8d10896c3ae9a70472d0d1440d073f945265fd115-image.png),![image.png](https://pic.leetcode-cn.com/7ac40b5c7d872fbaa6cefbe2a5672c3cfd2dec689507be287f35d3f1c1ece7b6-image.png)>

```Python []
class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        
        def helper(node, level):
            # start the current level
            if len(levels) == level:
                levels.append([])

            # append the current node value
            levels[level].append(node.val)

            # process child nodes for the next level
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)
            
        helper(root, 0)
        return levels
```

```Java []
class Solution {
    List<List<Integer>> levels = new ArrayList<List<Integer>>();

    public void helper(TreeNode node, int level) {
        // start the current level
        if (levels.size() == level)
            levels.add(new ArrayList<Integer>());

         // fulfil the current level
         levels.get(level).add(node.val);

         // process child nodes for the next level
         if (node.left != null)
            helper(node.left, level + 1);
         if (node.right != null)
            helper(node.right, level + 1);
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        return levels;
    }
}
```
**复杂度分析**

* 时间复杂度：$O(N)$，因为每个节点恰好会被运算一次。
* 空间复杂度：$O(N)$，保存输出结果的数组包含 `N` 个节点的值。

#### 方法 2：迭代

**算法**

上面的递归方法也可以写成迭代的形式。

我们将树上顶点按照层次依次放入*队列*结构中，队列中元素满足 FIFO（先进先出）的原则。在 Java 中可以使用[ `Queue` 接口中的 `LinkedList`](https://docs.oracle.com/javase/7/docs/api/java/util/Queue.html)实现。在 Python 中如果使用 [`Queue`](https://docs.python.org/3/library/queue.html) 结构，但因为它是为多线程之间安全交换而设计的，所以使用了锁，会导致性能不佳。因此在 Python 中可以使用 [`deque`](https://docs.python.org/3/library/collections.html#collections.deque) 的 `append()` 和 `popleft()` 函数来快速实现队列的功能。

第 0 层只包含根节点 `root` ，算法实现如下：

* 初始化队列只包含一个节点 `root` 和层次编号 `0` ： `level = 0`。
* 当队列非空的时候：
  * 在输出结果 `levels` 中插入一个空列表，开始当前层的算法。
  * 计算当前层有多少个元素：等于队列的长度。
  * 将这些元素从队列中弹出，并加入 `levels` 当前层的空列表中。
  * 将他们的孩子节点作为下一层压入队列中。
  * 进入下一层 `level++`。

**实现**
```Python []
from collections import deque
class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        
        level = 0
        queue = deque([root,])
        while queue:
            # start the current level
            levels.append([])
            # number of elements in the current level 
            level_length = len(queue)
            
            for i in range(level_length):
                node = queue.popleft()
                # fulfill the current level
                levels[level].append(node.val)
                
                # add child nodes of the current level
                # in the queue for the next level
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # go to next level
            level += 1
        
        return levels
```

```Java []
class Solution {
  public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> levels = new ArrayList<List<Integer>>();
    if (root == null) return levels;

    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    int level = 0;
    while ( !queue.isEmpty() ) {
      // start the current level
      levels.add(new ArrayList<Integer>());

      // number of elements in the current level
      int level_length = queue.size();
      for(int i = 0; i < level_length; ++i) {
        TreeNode node = queue.remove();

        // fulfill the current level
        levels.get(level).add(node.val);

        // add child nodes of the current level
        // in the queue for the next level
        if (node.left != null) queue.add(node.left);
        if (node.right != null) queue.add(node.right);
      }
      // go to next level
      level++;
    }
    return levels;
  }
}
```
复杂度分析

- 时间复杂度：$O(N)$，因为每个节点恰好会被运算一次。
- 空间复杂度：$O(N)$，保存输出结果的数组包含 N 个节点的值。

