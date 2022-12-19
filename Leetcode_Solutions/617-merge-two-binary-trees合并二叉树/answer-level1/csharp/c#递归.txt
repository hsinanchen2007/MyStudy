解题思路：
首先先判断t1是否为空，如果为空返回t2；如果t2为空则返回t1
当前面的if语句都没运行那么证明两方都不为空。那么先将两节点的值相加，然后再递归左节点，递归右节点。
（如有更好想法，方便的话还请指出。谢谢）

public class Solution {
    public TreeNode MergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null)
            {
                return t2;
            }
            if (t2 == null)
            {
                return t1;
            }

            /*
             * 当执行到这一步，说明节点一方不为空，应该储存两节点的和
             */
            TreeNode treeNode = new TreeNode(t1.val+t2.val);//计算节点值之和
            treeNode.left=MergeTrees(t1.left,t2.left);//计算右节点值之和
            treeNode.right=MergeTrees(t1.right, t2.right);//计算左节点之和
            return treeNode;
    }
}

![二叉树和.png](https://pic.leetcode-cn.com/af00008ecd8bc9270840027be6b9a40e2366ae43ee5a54925626b91d72970718-%E4%BA%8C%E5%8F%89%E6%A0%91%E5%92%8C.png)
