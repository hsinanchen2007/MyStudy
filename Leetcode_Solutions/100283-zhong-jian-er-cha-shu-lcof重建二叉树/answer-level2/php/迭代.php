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
     * @param Integer[] $preorder
     * @param Integer[] $inorder
     * @return TreeNode
     */
    function buildTree($preorder, $inorder) {
        if(empty($preorder) || empty($inorder)){
            return null;
        }
        $root=new TreeNode($preorder[0]);
        $length=count($preorder);

        $stack=[];
        array_push($stack,$root);
        $inorderIndex = 0;
        for ($i = 1; $i < $length; $i++) {
            $preorderVal = $preorder[$i];
             $node = end($stack);//栈顶
            if ($node->val != $inorder[$inorderIndex]) {
                $node->left = new TreeNode($preorderVal);
                 array_push($stack,$node->left );//尾部
            } else {
                while (!empty($stack) && end($stack)->val == $inorder[$inorderIndex]) {
                    $node = array_pop($stack);//尾部，栈顶
                    $inorderIndex++;
                }
               // print_r($node);
              //  echo $preorderVal;
                $node->right = new TreeNode($preorderVal);
                 array_push($stack,$node->right);//尾部
            }



        }
        return $root;
    }
}
```