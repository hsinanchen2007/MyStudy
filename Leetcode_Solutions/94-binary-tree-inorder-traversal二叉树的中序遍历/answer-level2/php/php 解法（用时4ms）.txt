关联：二叉树的[前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/php-jie-fa-by-andfly-27/)、[中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/php-jie-fa-yong-shi-4ms-by-andfly-2/)、[后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/php-jie-fa-by-andfly-28/) 解法
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer[]
     */
    function inorderTraversal($root) {
        $res = [];
        $this->helper($root,$res);
        return $res;
    }
    
    function helper($root,&$res){
        if($root == null) return;
        $this->helper($root->left,$res);
        $res[] = $root->val;
        $this->helper($root->right,$res);
    }
}
```
