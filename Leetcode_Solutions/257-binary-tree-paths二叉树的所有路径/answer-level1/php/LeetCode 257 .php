### 解题思路
类似先序迭代；多余一个栈用数组模拟tmp保存上一级path

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
     * @return String[]
     */
    function binaryTreePaths($root) {
       $res = $arr = $tmp= [];
       if($root == null) return $res;
       if($root->left ==null && $root->right ==null) return [(string)$root->val];
       array_push($arr,$root);
       array_push($tmp,$root->val);
       while(!empty($arr)){
          $rootNode = array_pop($arr);//后入后出
          $path = array_pop($tmp);//获取上一级的路径
          if($rootNode->left ==null && $rootNode->right ==null){
              $res[] = $path;
          }
          if($rootNode->right!=null){
              array_push($arr,$rootNode->right);
              array_push($tmp,$path.'->'.$rootNode->right->val);           
          }
          if($rootNode->left!=null){
              array_push($arr,$rootNode->left);
              array_push($tmp,$path.'->'.$rootNode->left->val);  
          }
          
       }

       return $res;
    }
}
```

### 解题思路
递归：核心传一个path字符串过去

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
     * @return String[]
     */
    function binaryTreePaths($root) {
        $res = [];
        $this->getPaths($root,'',$res);
        return $res;
    }

    function getPaths($root,$path,&$res){
        if($root == null) return null;
        $path .= $root->val;
        if($root->left == null && $root->right ==null){
            $res[] = $path;
        } 
        $this->getPaths($root->left,$path.'->',$res);
        $this->getPaths($root->right,$path.'->',$res);
    }
}
```