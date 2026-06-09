### 解题思路
此处撰写解题思路

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
     * @param TreeNode $t
     * @return String
     */
    function tree2str($t) {
         if($t==null)//if 二叉树为空输出''
            return "";
        if($t->left==null && $t->right==null)
            return $t->val."";//if 当前节点左子树和右子树都为空
        if($t->right==null)//if 当前右子树为空就只传左子树
            return $t->val."(".$this->tree2str($t->left).")";
        return $t->val."(".$this->tree2str($t->left).")(".$this->tree2str($t->right).")";   
    }
}
```