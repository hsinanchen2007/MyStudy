### 解题思路
递归思路

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
    function findSecondMinimumValue($root) {
      if($root ==null) return -1;
      $min1 = $root->val;//最小的值一定是根节点的值
      $min2 = -1;//第2小的值默认-1
      $this->help($root,$min1,$min2);
      return $min2;
        
    }

    function help($root,$min1,&$min2){
        if($root ==null) return;
        if($root->val > $min1){//只判断当前值大于根节点的情况
            if($min2 == -1){
                //如果第2小为-1说明是第一次直接赋值
                $min2 = $root->val;
            }else{
                //否则则当前值和第2小的值取最小值
                $min2 = min($root->val,$min2);
            }
        }
        $this->help($root->left,$min1,$min2);
        $this->help($root->right,$min1,$min2);
    }
}
```

### 解题思路
迭代思路：
先序遍历

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
    function findSecondMinimumValue($root) {
      if($root ==null) return -1;
      $min1 = $root->val;//最小的值一定是根节点的值
      $min2 = -1;//第2小的值默认-1
      $arr = [];//模拟栈
      array_push($arr,$root);
      while(!empty($arr)){
          $node  = array_pop($arr);
          if($node->val > $min1){
              if($min2 == -1 || $node->val < $min2){
                  $min2 = $node->val;
              }
          }
         if($node->right !=null) array_push($arr,$node->right);
         if($node->left !=null) array_push($arr,$node->left);
      }

      return $min2;
        
    }
}
```