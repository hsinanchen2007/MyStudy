思路：根据二叉搜索树的定义，大于根结点的值都在右子树上，小于根结点的值都在左子树上，于是此题要求将二叉搜索树转变为更大和树，便可等价为求某个节点右边的节点和加上当前节点值（这个值就是题目所说的更大和）赋值给当前节点的新树，那么如何求这个更大和呢？根据二叉搜索树的性质，我们只需按照反转的中序遍历即可求到某个节点的更大值和。<br/><br/>
于是解题代码如下：
```
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        return root;
    }
    
    int sum = 0;// 记录每个节点的右边的所有节点和，即原树中大于 node.val 的值之和
    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        
        dfs(root.right);// 先访问所有大于root的节点
        root.val += sum;// 赋值给当前节点
        sum = root.val;// 保存更大和
        dfs(root.left);// 后访问小于root的节点
    }
}
```