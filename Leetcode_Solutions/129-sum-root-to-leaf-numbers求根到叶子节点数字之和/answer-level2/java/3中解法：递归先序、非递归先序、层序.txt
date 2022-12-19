
**思路一:**

二叉树的题目我们首先想到的就是递归求解。递归的方式很简单，用先序遍历的变形。

1. 先遍历根节点；
2. 遍历左子树，遍历左子树的时候，把走当前路径的数字带到左子树的求解中；
3. 遍历右子树，遍历右子树的时候，把走当前路径的数字带到右子树的求解中；
4. 更新总的和。

**代码一:**
```java [-Java]
class Solution {
    private int sum = 0;
    private void helper(TreeNode node, int father) {
        if (node == null) return ;
        int current = father * 10 + node.val;
        if (node.left == null && node.right == null) {
            sum += current;
            return;
        }
        helper(node.left, current);
        helper(node.right, current);
    }

    public int sumNumbers(TreeNode root) {
        if (root == null) return sum;
        helper(root, 0);
        return sum;
    }
}
```
**思路二:**

通常还可以用 `stack` 的思路来解递归的题目。先序非递归的代码我们知道是用 `stack` 来保存遍历过的元素。而因为本题要记录到叶节点的数字，所以需要一个额外的 `stack` 来记录数字。每次出 `stack` 之后，如果是叶子节点，那么加和；如果不是，那么就看左右子树，入 `stack`。

**代码二:**
```java [-Java]
class Solution {
    public int sumNumbers(TreeNode root) {
        int sum = 0;
        if (root == null) return sum;
        Stack<TreeNode> nodeStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();
        nodeStack.add(root);
        numStack.add(0);
        while (!nodeStack.isEmpty()) {
            TreeNode current = nodeStack.pop();
            Integer currentNum = numStack.pop() * 10 + current.val;
            if (current.left == null && current.right == null) {
                sum += currentNum;
            }
            if (current.left != null) {
                nodeStack.add(current.left);
                numStack.add(currentNum);
            }
            if (current.right != null) {
                nodeStack.add(current.right);
                numStack.add(currentNum);
            }
        } 
        return sum;
    }
}
```
**思路三:**

其实，我们可以看到，最关键的是找到叶子节点，然后加和这个操作。叶子节点我们同样可以用层序遍历的方式来解这道题目。层序遍历用队列来解。

**代码三:**

```java [-Java]
public class Solution {
    public int sumNumbers(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        Queue<Integer> numQueue = new LinkedList<Integer>();
        if(root == null) return 0;
        int res = 0;
        queue.add(root);
        numQueue.add(0);
        while(!queue.isEmpty()) {
            int size = queue.size();
            // 把该层的都入队，同时如果遇到叶节点，计算更新
            while(size-- > 0) {
                root = queue.poll();
                int val = numQueue.poll() * 10 + root.val;
                if(root.left == null && root.right == null)
                    res += val;
                if(root.left != null) {
                    queue.add(root.left);
                    numQueue.add(val);
                }
                if (root.right != null) {
                    queue.add(root.right);
                    numQueue.add(val);
                }
            }
        }
        return res;
    }
}
```

总结，二叉树的题目，大多数都是遍历的变形，面试时候看用 `bfs`，还是 `dfs`，一般来说很快就能得出答案。写非递归代码的时候，注意判断一下非空，不要把 `null` 节点入队或者入栈。


