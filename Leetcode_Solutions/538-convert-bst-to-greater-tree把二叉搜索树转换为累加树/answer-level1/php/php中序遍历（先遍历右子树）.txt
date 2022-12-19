思路：中序遍历的结果是从小到大排序（先遍历左子树），如果先遍历右子树就是从大到小排序。利用先遍历右子树，每次遍历到一个元素，就加上上一个元素的值，更新节点。
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
     * @return TreeNode
     */
    private $last=0;    //累加值

    function convertBST($root) {
        $this->inOrder($root);
        return $root;
    }

    //中序遍历，先遍历右子树
    function inOrder($root){
        if($root==null){
            return;
        }            

        $this->inOrder($root->right);
        $root->val+=$this->last;    //更新节点值
        $this->last=$root->val; //更新累加值
        $this->inOrder($root->left);
    }
}
```
