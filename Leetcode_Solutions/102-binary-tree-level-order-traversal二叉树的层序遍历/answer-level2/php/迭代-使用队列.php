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
     * @return Integer[][]
     */
    function levelOrder($root) {
        if(empty($root)){
            return [];
        }
        $arrQ=[];
        $level=0;
        array_push($arrQ,$root);
        
        $arr=[];//每层只输出栈里面所有的数据
       while(!empty($arrQ)){
           $l=count($arrQ);
           for($i=0;$i<$l;$i++){
               $node=array_shift($arrQ);
               $arr[$level][]=$node->val;

               if($node->left){
                   array_push($arrQ,$node->left);
               }
               if($node->right){
                    array_push($arrQ,$node->right);
               }
           }
             $level++;
       }
       return $arr;
    }

}
```