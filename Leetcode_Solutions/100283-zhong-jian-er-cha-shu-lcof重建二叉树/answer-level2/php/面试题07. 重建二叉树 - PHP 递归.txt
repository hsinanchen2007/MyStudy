### 解题思路

1. 用前序遍历的第一个节点**分割**中序遍历的结果，左边的元素即当前结点的**左子树**，右边的元素即**右子树**
2. 递归：前序遍历第一个**有效节点**（若第一个节点在当前拆分的中序遍历中不存在，则继续指针向右找出下一个存在的），执行步骤1

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

        // 到了叶子节点后，中序遍历被分割完了，使用 null 作为退出条件
       if (count($inorder) == 0 || count($preorder) == 0) {
            return null;
        }


        // 前序遍历中找出有效节点的坐标
        $span = 0;
        while ($span < count($preorder) AND array_search($preorder[$span], $inorder) === false) {
            $span += 1;
        }

        if ($span == count($preorder)){
            // 找不到（坐标出界）-> 目标不在这一边的子树，返回 null
            return null;
        } else {
            $cur = array_search($preorder[$span], $inorder);
        }

        // 拆分两边
        $left = array_slice($inorder, 0, $cur);
        $right = array_slice($inorder, $cur + 1, count($inorder) - $cur);
        
        // 构造节点 
        $tree = new TreeNode($preorder[$span]);
        $tree->left = $this->buildTree(array_slice($preorder, $span + 1, count($preorder) -1), $left);
        $tree->right = $this->buildTree(array_slice($preorder, $span + 1, count($preorder) -1), $right);

        return $tree;
    }
}
```