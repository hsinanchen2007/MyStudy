**1. 四大算法回顾。分治、动规、回溯、贪心，都可以归结到树结构的遍历。**
分治：将原问题的解分解为若干子问题的解，子问题的解又可以继续分解成更小的子问题的解。自底向上的思维。
动规：可以认为就是分治，只是强调了在分解子问题的过程中，不会重复计算同样的子问题。自底向上的思维。
回溯：穷举所有决策路径，每走一步都会到达一个子问题，直到该条路径走到了最小子问题，就开始回头走另外的路径。自顶向下的思维。
贪心：每走一步都会到达一个子问题，然后根据贪心策略做出选择，直到走到了最小子问题，就认为已经求得了原问题的解。
**2.四大算法求解的问题类型**
多阶段决策问题（而不只是最优化！具体是求最值、数量、布尔还是具体决策方案只是问题形式不同）。这种问题总可以分解成同构的子问题，可能的解空间就是所有决策路径的集合。
**3.四大算法的时间复杂度**
分治和回溯都穷举了可能解空间中的所有路径，复杂度往往是指数级或阶乘级；
动规在子问题无重叠的情况下枚举了可能解空间中的某几条路径，复杂度也是指数级或阶乘级，但实际效率会高一些；
贪心则是只选了可能解空间中的一条路径，复杂度往往是线性级或幂级。但是如果问题本身不具有贪心选择性质，得出的答案不一定正确。
**4.四大算法的实现方式**
分治/动态规划：一般管递归形式的叫分治，dp table形式的叫动规。实际上不需要这么区分，带记忆化的可以统称为动规。递归函数一般带有返回值，递归入参就是状态变量，对应dp table的维；
回溯：一般是递归形式，递归函数一般无返回值（对于除了求具体决策方案的其他问题形式，可能带返回值），入参带有已走的路径和状态变量，通过状态变量得出选择列表；
贪心无固定实现方式，具体问题具体分析。
**5.和树结构的渊源**
多阶段决策问题，面临的局面就是状态，做出决策就会导致状态转移。因为子状态可以继续递推分解，就和树一样具有天然的递归性质。
对应到树中，状态就是节点，状态转移/做出决策就是边，最小的子状态就是叶子，原问题/原状态就是根。


# 解法一
**算法：BFS
实现方式：迭代**
```
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int level = 0;
        stop: while (!queue.isEmpty()) {
            level++;
            int count = queue.size();
            for (int i = 0; i < count; i++) {
                root = queue.poll();
                if (root.left == null && root.right == null) break stop;
                if (root.left != null) queue.offer(root.left);
                if (root.right != null) queue.offer(root.right);
            }
        }
        return level;
    }
}
```
# 解法二
**算法：分治/动态规划/DFS
实现方式：自底向上/递归**
```
class Solution {
    public int minDepth(TreeNode root) {
        // 基本情况 dp[null] = 0 ，dp[叶子] = 1
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;

        // 状态转移方程 
        //              / dp[右孩子] + 1 ，左孩子为null
        // dp[非叶子] =    dp[左孩子] + 1 ，右孩子为null
        //              \ min(dp[左孩子], dp[右孩子]) + 1 ，左右孩子都不为null
        if (root.left == null) return minDepth(root.right) + 1;
        if (root.right == null) return minDepth(root.left) + 1;
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
}
```
# 解法三
**算法：回溯/DFS
实现方式：自顶向下/递归**
```
class Solution {
    public int minDepth(TreeNode root) {
        return minDepth(root, 1);
    }

    // depth 已走过的路径
    // root 当前状态（dp数组的维）
    private int minDepth(TreeNode root, int depth) {
        // 最小子状态
        if (root == null) return depth - 1;
        if (root.left == null && root.right == null) return depth;

        // 由状态变量得出选择列表
        // 该层调用返回，相当于回溯，因为上层的depth比该层小1
        if (root.left == null) return minDepth(root.right, depth + 1);
        if (root.right == null) return minDepth(root.left, depth + 1);
        return Math.min(minDepth(root.left, depth + 1), minDepth(root.right, depth + 1));
    }
}
```
# 解法四（1）
**算法：DFS/后序遍历
实现方式：迭代，使用变量保存上一次访问的节点**
```
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode last = null;
        int level = 0, minLevel = Integer.MAX_VALUE;
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.addLast(root);
                level++;
                root = root.left;
            }
            TreeNode tmp = stack.peekLast();
            if (tmp.right != null && tmp.right != last) {
                root = tmp.right;
            } else {
                if (tmp.left == null && tmp.right == null) minLevel = Math.min(minLevel, level);
                last = stack.removeLast();
                level--;
            }
        }
        return minLevel;
    }
}
```
# 解法四（2）
**算法：DFS/后序遍历
实现方式：迭代，每个节点入栈出栈两次**
```
 class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Deque<TreeNode> stack = new ArrayDeque<>();
        int level = 0, minLevel = Integer.MAX_VALUE;
        stack.addLast(root);
        stack.addLast(root);
        while (!stack.isEmpty()) {
            root = stack.removeLast();
            if (root == stack.peekLast()) {
                level++;
                if (root.right != null) {
                    stack.addLast(root.right);
                    stack.addLast(root.right);
                }
                if (root.left != null) {
                    stack.addLast(root.left);
                    stack.addLast(root.left);
                }
            } else {
                if (root.left == null && root.right == null) minLevel = Math.min(minLevel, level);
                level--;
            }
        }
        return minLevel;
    }
}
```


