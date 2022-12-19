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
    function rightSideView($root) {
        //思路  层次遍历的变种 
        $res = $arr = [];
        if($root == null) return $res;
        array_push($arr,$root);
        while($count = count($arr)){
            $tmp = [];
            for($i=0;$i<$count;$i++){
                $node  = array_shift($arr);//先入先出
                $tmp = $node->val;//只保留最后一个节点
                if($node->left !=null) array_push($arr,$node->left);
                if($node->right !=null) array_push($arr,$node->right);
            }

            $res[] = $tmp;
        }
        return $res;
    }

}
```