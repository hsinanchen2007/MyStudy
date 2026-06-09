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
     * @return TreeNode
     */
    function bstFromPreorder($preorder) {
        if(empty($preorder)){
            return null;
        }
        //1、根据给定的先序遍历的数组，构建树
        //取出根节点的值
        $rootval = array_shift($preorder);
        $root = new TreeNode($rootval);
        $left = $right = [];

        while(!empty($preorder)){
            $current = array_shift($preorder);
            if($current > $rootval){
                //比根节点大的就是根的右子树
                $right[] = $current;
            }else{
                //比根节点小的就是根的左子树
                $left[] = $current;
            }
        }
        //递归遍历左右子树
        $root->left = $this->bstFromPreorder($left);
        $root->right = $this->bstFromPreorder($right);
        return $root;
    }
 
}
```