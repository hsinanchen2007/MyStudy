### 解题思路
见代码

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

    private $res=[];
    private $item=[];
    /**
     * @param TreeNode $root
     * @param Integer $sum
     * @return Integer[][]
     */
    function pathSum($root, $sum) {
        $this->helper($root,$sum);
        return $this->res;
    }

    function helper($root,$expect_num){
        if($root==null) return ;

        $cur_num = $root->val;
        $expect_num -= $cur_num;
        array_push($this->item,$cur_num);
        
        //判断是否为叶子节点，如果是叶子节点，并且所有数加起来是期望的数了
        if($expect_num == 0 && $root->left==null && $root->right==null){
            array_push($this->res,$this->item);
        }
        
        $this->helper($root->left,$expect_num);
        $this->helper($root->right,$expect_num);
        //找到路径后，或者没找到路径，需要回退的时候，将item数组清理干净
        array_pop($this->item);
    }
}
```