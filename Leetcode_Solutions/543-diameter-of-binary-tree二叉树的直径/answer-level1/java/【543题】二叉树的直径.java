**方法一：深度优先搜索(DFS)**
```
class Solution {
    /**
    * 思路：
    * 由题知道求二叉树的直径就是求头结点左边分支的深度加右边分支的深度。
    */
    int ans;
    public int diameterOfBinaryTree(TreeNode root) {
        // 记录左右直径中的最大值
        ans = 1;
        depth(root);
        return ans - 1;
    }
    public int depth(TreeNode node) {
        if (node == null){
			return 0; // 访问到空节点了，返回0
		}
        int L = depth(node.left); // 左儿子为根的子树的深度
        int R = depth(node.right); // 右儿子为根的子树的深度
        ans = Math.max(ans, L+R+1); // 计算d_node即L+R+1 并更新ans
        return Math.max(L, R) + 1; // 返回该节点为根的子树的深度
    }
}
```
