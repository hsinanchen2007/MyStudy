### 解题思路
最难懂的就是这个平衡

if(abs($left-$right)>1){
     $bool = false;
}

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
     * @return Boolean
     */
    function isBalanced($root) {
        $bool = true;
        $this->getDepth($root,$bool);
        return $bool;
    }

    function getDepth($root,&$bool){
        if ($root ==null) {
            return 0;
        }
        $left = $this->getDepth($root->left,$bool);
        $right = $this->getDepth($root->right,$bool);
        if(abs($left-$right)>1){
            $bool = false;
        }
        return $right>$left?$right+1:$left+1;
    }
}
```