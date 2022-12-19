### 解题思路
根据先序和中序遍历特点，把整个序列进行左右划分，分别构造左右子树即可

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
        if (empty($preorder)) {
            return null;
        }
        $preRootValue = $preorder[0];
        $root = new TreeNode($preRootValue);
        $inRootIndex = array_search($preRootValue, $inorder);
        // 用于构造左子树的中序遍历序列
        $leftInOrder = array_slice($inorder, 0, $inRootIndex);
        // 用于构造右子树的中序遍历序列
        $rightInOrder = array_slice($inorder, $inRootIndex+1);
        // 用于构造左子树的先序遍历序列
        $leftPreOrder = array_slice($preorder, 1, $inRootIndex);
        // 用于构造右子树的先序遍历序列
        $rightPreOrder = array_slice($preorder, $inRootIndex+1);
        // 构造左子树
        $root->left = $this->buildTree($leftPreOrder, $leftInOrder);
        // 构造右子树
        $root->right = $this->buildTree($rightPreOrder, $rightInOrder);
        return $root;
    }
}
```