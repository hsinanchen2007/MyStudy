### 解题思路
官方题解

### 代码

```php
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */

    /*
    int maxd=0;
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return maxd;
    }
    public int depth(TreeNode node){
        if(node==null){
            return 0;
        }
        int Left = depth(node.left);
        int Right = depth(node.right);
        maxd=Math.max(Left+Right,maxd);//将每个节点最大直径(左子树深度+右子树深度)当前最大值比较并取大者
        return Math.max(Left,Right)+1;//返回节点深度
    }
    */

    protected $result = 0;
    /**
     * @param TreeNode $root
     * @return Integer
     */
    function diameterOfBinaryTree($root)
    {
        $this->depth($root);
        return $this->result;
    }

    // 递归函数的含义，找出以当前节点为根节点的子树的最大深度
    private function depth($node)
    {
        if ($node === null) return 0;
        $leftDepth = $this->depth($node->left);
        $rightDepth = $this->depth($node->right);
        $this->result = max($this->result, $leftDepth + $rightDepth);
        return max($leftDepth, $rightDepth) + 1;
    }
}
```