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
     * @param TreeNode $root
     * @return Integer[]
     */
    function levelOrder($root) {
        //层次遍历
        $res = $arr = [];
        if($root == null) return $res;
        array_push($arr,$root);//模拟队列（先入先出）
        while($count=count($arr)){
             for($i=0;$i<$count;$i++){
                 $node = array_shift($arr);
                 if($node !=null) $res[] = $node->val;
                 if($node->left !=null) array_push($arr,$node->left);
                 if($node->right !=null) array_push($arr,$node->right);
             }
        }

        return $res;
    }

   

    
}
```