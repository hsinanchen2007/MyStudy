### 解题思路
层次遍历变种，根据层级处理插入头部还是尾部（或者可以翻转数组）

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
     * @return Integer[][]
     */
    function levelOrder($root) {
        $res = [];
        $this->helper($root,0,$res);
        return $res;
    }

    function helper($root,$level,&$res){
        if($root ==null) return ;
        if($level==count($res)){
            $res[$level] = []; 
        }
        if($level%2){
        array_unshift($res[$level],$root->val);
        }else{
        array_push($res[$level],$root->val);
        }
        $this->helper($root->left,$level+1,$res);
        $this->helper($root->right,$level+1,$res);
    }
}
```