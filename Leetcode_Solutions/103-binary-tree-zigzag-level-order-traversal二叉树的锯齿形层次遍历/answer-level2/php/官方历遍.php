### 解题思路
历遍方法

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
    function zigzagLevelOrder($root) {
        if($root ==null){
            return [];
        }

        $res = $arr = [];

        array_push($arr,$root);
        $levelArr = [];
        $level = 1;
        // print_r($arr);
        
        //count($arr) returns the number of non-empty nodes of the current level
        while($count = count($arr)){
            for($i=$count;$i>0;$i--){
                $node = array_shift($arr);//pop out the first element of the array(Tree)
                $levelArr[] = $node->val;
                
                //push the non-empty nodes in the level to the next cycle of loop
                if($node->left !=null) array_push($arr,$node->left);
                if($node->right !=null) array_push($arr,$node->right);
            }

            if ($level%2 == 0) {//偶数就翻转数组
                $levelArr = array_reverse($levelArr);
            }
            array_push($res, $levelArr);
            $level++;
            $levelArr = [];
        }
        return $res;

    }
}
```