### 解题思路
递归算法：类似最小深度

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
    function maxDepth($root) {
        if($root ==null ) return 0;
        if($root->left == null) return $this->maxDepth($root->right)+1;
        if($root->right== null) return $this->maxDepth($root->left)+1; 
        return max($this->maxDepth($root->left),$this->maxDepth($root->right))+1;
    }
}
```

### 解题思路
迭代算法：层次遍历；类似最小深度

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
    function maxDepth($root) {
        if($root ==null ) return 0;
        if($root->left == null && $root->right ==null) return 1;
        $min = 0;  
        $arr = [];
        array_push($arr, $root);
        while($count = count($arr)){
            $min++;
            for($i=$count;$i>0;$i--){
                $node = array_shift($arr);//先入先出
                if($node->left == null && $node->right ==null){
                    continue;
                }
                if($node->left !=null) array_push($arr,$node->left);
                if($node->right !=null) array_push($arr,$node->right);
            }
        }

        return $min;
    }
}
```