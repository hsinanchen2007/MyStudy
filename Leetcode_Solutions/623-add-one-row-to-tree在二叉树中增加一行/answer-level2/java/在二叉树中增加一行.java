#### 方法一：深度优先搜索（递归）

如果 `d` 的值为 `1`，我们就添加一个节点，并将整棵树作为新节点的左子树。否则我们可以使用深度优先搜索找出所有 `d` 层的节点并进行操作。在搜索时，我们需要记录当前节点的深度 `depth`，如果此时 `depth == d - 1`，那么我们需要在当前节点的左右孩子各增加一个节点。如果当前节点的左右孩子已经有节点，我们就将这些节点存储到临时变量中，在增加新节点后再把左右孩子作为新节点的左子树或右子树，并结束递归。如果 `depth != d - 1`，我们就需要对当前节点的子节点进行递归搜索。

<![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide14.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide15.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_Recursion_NewSlide16.PNG)>


```Java [sol1]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode addOneRow(TreeNode t, int v, int d) {
        if (d == 1) {
            TreeNode n = new TreeNode(v);
            n.left = t;
            return n;
        }
        insert(v, t, 1, d);
        return t;
    }

    public void insert(int val, TreeNode node, int depth, int n) {
        if (node == null)
            return;
        if (depth == n - 1) {
            TreeNode t = node.left;
            node.left = new TreeNode(val);
            node.left.left = t;
            t = node.right;
            node.right = new TreeNode(val);
            node.right.right = t;
        } else {
            insert(val, node.left, depth + 1, n);
            insert(val, node.right, depth + 1, n);
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是二叉树的节点个数。我们最多会遍历 $N$ 个节点。

* 空间复杂度：$O(N)$。在最坏情况下，需要递归 $N$ 层，用到 $O(N)$ 的栈空间。

#### 方法二：深度优先搜索（非递归）

我们可以直接用栈来模拟递归，实现深度优先搜索的非递归版本。

我们首先将根节点入栈，随后每次栈顶的元素即为当前搜索到的结点，我们取出这个节点，根据 `depth` 和 `d - 1` 的关系为当前节点增加新的子节点，或者将当前节点的子节点全部入栈，继续搜索。

<![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_StackSlide11.PNG)>

```Java [sol2]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    class Node{
        Node(TreeNode n,int d){
            node=n;
            depth=d;
        }
        TreeNode node;
        int depth;
    }
    public TreeNode addOneRow(TreeNode t, int v, int d) {
        if (d == 1) {
            TreeNode n = new TreeNode(v);
            n.left = t;
            return n;
        } 
        Stack<Node> stack=new Stack<>();
        stack.push(new Node(t,1));
        while(!stack.isEmpty())
        {
            Node n=stack.pop();
            if(n.node==null)
                continue;
            if (n.depth == d - 1 ) {
                TreeNode temp = n.node.left;
                n.node.left = new TreeNode(v);
                n.node.left.left = temp;
                temp = n.node.right;
                n.node.right = new TreeNode(v);
                n.node.right.right = temp;
                
            } else{
                stack.push(new Node(n.node.left, n.depth + 1));
                stack.push(new Node(n.node.right, n.depth + 1));
            }
        }
        return t;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是二叉树的节点个数。我们最多会遍历 $N$ 个节点。

* 空间复杂度：$O(N)$。

#### 方法三：广度优先搜索

我们同样可以使用广度优先搜索解决这个问题，并且广度优先搜索是最容易理解且最直观的一种方法。

我们将根节点放入队列 `queue`。在每一轮搜索中，如果 `queue` 中节点的深度为 `d - 1`（显然 `queue` 中所有的节点都在同一深度），我们就退出搜索，并为 `queue` 中所有节点添加新的子节点；否则我们将 `queue` 中所有节点的子节点放入新的队列 `temp` 中，再用 `temp` 替代 `queue`。

<![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/623/623_Add_One_Row_queue_newSlide13.PNG)>

```Java [sol3]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode addOneRow(TreeNode t, int v, int d) {
        if (d == 1) {
            TreeNode n = new TreeNode(v);
            n.left = t;
            return n;
        }
        Queue < TreeNode > queue = new LinkedList < > ();
        queue.add(t);
        int depth = 1;
        while (depth < d - 1) {
            Queue < TreeNode > temp = new LinkedList < > ();
            while (!queue.isEmpty()) {
                TreeNode node = queue.remove();
                if (node.left != null) temp.add(node.left);
                if (node.right != null) temp.add(node.right);
            }
            queue = temp;
            depth++;
        }
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();
            TreeNode temp = node.left;
            node.left = new TreeNode(v);
            node.left.left = temp;
            temp = node.right;
            node.right = new TreeNode(v);
            node.right.right = temp;
        }
        return t;
    }
}
```

**复杂度分析s**

* 时间复杂度：$O(N)$，其中 $N$ 是二叉树的节点个数。我们最多会遍历 $N$ 个节点。

* 空间复杂度：$O(N)$。