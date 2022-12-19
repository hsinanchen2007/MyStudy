### 解题思路
第一步找到要删除的节点，第二步，删除之，注意删除后的节点位置变化。

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
     * @param Integer $key
     * @return TreeNode
     */
    function deleteNode($root, $key) {
        $node = $root;
        $parent = null;
        $pos = '';
        while($node->val != $key){
            $parent = $node;
            if($key < $node->val){
                if($node->left != null){
                    $pos = 'left';
                    $node = $node->left;
                }else{
                    return $root;
                }
            }else if($key > $node->val){
                if($node->right != null){
                    $pos = 'right';
                    $node = $node->right;
                }else{
                    return $root;
                }
            }
        }
        $root2 = $this->doDelete($node);

        if($parent == null){
            return $root2;
        }

        if($pos == 'left'){
            $parent->left = $root2;
        }else if($pos == 'right'){
            $parent->right = $root2;
        }

        return $root;
    }

    //待删除节点，返回删除后的本位置的节点
    function doDelete($node){
        if($node->left == null && $node->right == null){
            return null;
        }else if($node->left == null && $node->right != null){
            return $node->right;
        }else if($node->left != null && $node->right == null){
            return $node->left;
        }else{
            $left = $node->left;
            $right = $node->right;

            $lr = $left->right;

            $left->right = $right;
            $curr = $right;
            while($curr->left != null){
                $curr = $curr->left;
            }
            $curr->left = $lr;

            return $left;
        }
    }
}

























```