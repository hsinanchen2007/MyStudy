因为，树的高度和根的高度在概念上等价，树的深度和最远叶子的深度在概念上等价；这两个高度和两个深度又在数值上相等。所以，采用DFS的话有两种思考方式：
1. 自底向上（计算高度）。叶的高度是1，双亲的高度是左右子树的最大高度+1，如此递推，直到根，得到根的高度，即整棵树的高度，即整棵树的深度；
2. 自顶向下（计算深度）。根的深度是1，孩子的深度是当前节点的深度+1，如此递推，直到叶子，最远叶子的深度即整棵树的深度。
# 解法一：自底向上地递归
```
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}
```
# 解法二：自底向上地迭代
该解法和法一的思想完全一致，都是先一探到底，然后从最底层节点开始向上回溯从0更新高度。
采用后序遍历。迭代地后序遍历的方式很多，比如存储上次访问节点；每个节点入栈两次等。但必须是按树的拓扑结构进行遍历的方式，不能是那种 “根->右->左”倒序输出的方式
使用两个显式栈，stack用来遍历，subTreeHeight存储当前出栈节点的左右子树高度。当到达某个节点时，用其左右子树高度的较大者加一入subTreeHeight栈。循环结束后，subTreeHeight中剩的唯一元素就是根节点的高度，即整棵树的最大深度
```
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> subTreeHeight = new Stack<>();
        // 1.此处必须new一个节点，不能赋值null。该变量用于保存上一个遍历的节点
        TreeNode last = new TreeNode(0);
        while (root != null || !stack.empty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            TreeNode tmp = stack.peek();
            // 2.该判断条件是为了防止从右子树回来时重复push 0。且，如果上述1处赋值null，这里会在节点的右子树中的最右叶子处少push一个0，在下面pop时导致空栈异常
            if (tmp.left == null && last != tmp.right) subTreeHeight.push(0);
            if (tmp.right != null && last != tmp.right) {
                root = tmp.right;
            // 3.当前遍历节点为叶子或从右子树回到当前遍历节点时，更新以该节点为根的树的最大深度并将深度值入栈
            } else {
                if (tmp.right == null) subTreeHeight.push(0);
                last = stack.pop();
                subTreeHeight.push(Math.max(subTreeHeight.pop(), subTreeHeight.pop()) + 1);
            }
        }
        return subTreeHeight.pop();
    }
}
```
# 解法三：自顶向下地递归
```
class Solution {
    public int maxDepth(TreeNode root) {
        return maxDepth(root, 0);
    }

    private int maxDepth(TreeNode root, int level) {
        if (root == null) return level;
        if (root.left == null && root.right == null) return level + 1;
        return Math.max(maxDepth(root.left, level + 1), maxDepth(root.right, level + 1));
    }
}
```
# 解法四：自顶向下地迭代
该解法和法三的思想完全一致，每个遍历节点都知道自己的深度，当到达叶子时，用叶子的深度和当前记录的最大深度比较
采用前序遍历。使用两个显式栈，模拟递归调用中的栈帧积累，存储节点及其对应的深度。当到达叶子节点时，比较其深度和当前记录的最大深度的大小，并更新最大深度
```
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> level = new Stack<>();
        int depth = 0;
        stack.push(root);
        level.push(1);
        while (!stack.empty()) {
            root = stack.pop();
            int curLevel = level.pop();
            if (root.left == null && root.right == null) {
                if (curLevel > depth) depth = curLevel;
            }
            if (root.right != null) {
                stack.push(root.right);
                level.push(curLevel + 1);
            }
            if (root.left != null) {
                stack.push(root.left);
                level.push(curLevel + 1);
            }
        }
        return depth;
    }
}
```
# 解法五：BFS
用队列层序遍历...
