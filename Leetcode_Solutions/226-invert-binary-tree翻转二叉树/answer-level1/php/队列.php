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
        迭代
     * @param TreeNode $root
     * @return TreeNode
     */
    function invertTree($root) {
        if(empty($root)){
            return $root;
        }
        $queue=[];//队列
        array_push($queue,$root);
        while(!empty($queue)){
            $cuurent=array_shift($queue);
            $temp=$cuurent->left;
            $cuurent->left=$cuurent->right;
            $cuurent->right=$temp;
            if($cuurent->left){
                array_push($queue,$cuurent->left);
            }
            if($cuurent->right){
                array_push($queue,$cuurent->right);
            }
        }
        return $root;




    }
}
```