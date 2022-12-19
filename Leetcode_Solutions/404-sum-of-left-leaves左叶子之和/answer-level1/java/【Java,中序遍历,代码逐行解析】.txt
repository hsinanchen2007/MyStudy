>题目简介

计算给定二叉树的所有左叶子之和。

示例：

        3
       / \
      9  20
        /  \
       15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

<br>

>先上代码，再结合代码讲解思路
```java
class Solution {
    // 记录左叶子节点值总和
    int sum = 0;

    public int sumOfLeftLeaves(TreeNode root) {
        // 如果根节点为null，则直接返回 0
        if (root == null) {
            return 0;
        }

        // 如果根节点无子节点，则直接返回 0
        if (root.left == null && root.right == null) {
            return 0;
        }

        // 进行递归
        leftSum(root);

        // 递归处理完，返回sum即可
        return sum;
    }

    // 计算左叶子节点值总和
    // 核心思想是树的中序遍历 即 左中右
    public void leftSum(TreeNode node) {
        // 如果当前节点为null ，直接return 即可
        if (node == null) {
            return ;
        }
        // 取出当前节点的左右节点，为了方便调用
        TreeNode left = node.left;
        TreeNode right = node.right;

        // 根据中序遍历，先进行左边节点的处理
        leftSum(left);

        // 根据中序遍历，再进行中间节点（即当前节点）的处理
        // 这里判断 左节点不为null 且 左节点无子节点 即可判断该 左节点是左叶子节点
        if (left != null && left.left == null && left.right == null) {
            // 符合条件即进行累加
            sum += left.val;
        }
        // 根据中序遍历，最后进行右边节点（即当前节点）的处理
        leftSum(right);
    }
}
```
<br>

>**思路讲解**

    我们从题目分析，题目的核心要求有两点
    1. 左叶子节点
    2. 值求和
    
    那么只要我们解决了这两点，问题就迎刃而解。
    
    1. 首先我们要知道如何判断一个左叶子节点。
        a. 叶子节点
        叶子节点即无子节点
        b. 左节点，即左子节点
        综上，我们可以知道判断左叶子节点的核心是，当前节点的左子节点且该左子节点无子节点（读三遍！！！）
    2. 第二点，关于求和
        这个问题，想必很多小伙伴早就知道啦~ 刷leetcode的过程中遇到了许多求和的问题。
        这里，我们可以声明一个成员变量int sum 去记录即可


    解决了以上问题，接下来我们只需要利用树的中序遍历即可，
    这里小伙伴也可以看个人喜欢使用前序或者后续遍历的思想，都是正确的。
    
    即按找先处理左，再处理中，最后处理右的思路写即可
    
    代码的核心都在注释喔，有不同意见的可以在评论区交流~
    
   

