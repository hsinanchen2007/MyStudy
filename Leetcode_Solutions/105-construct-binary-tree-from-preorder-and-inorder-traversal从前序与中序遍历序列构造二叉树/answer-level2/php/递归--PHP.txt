### 解题思路
咋看这道题不知道在讲啥，细看就是已知一棵二叉树的前序遍历和中序遍历，还原这颗树。

算法：递归
- 前序遍历的第一个元素就是树根的值。
- 在中序遍历中，树根左侧的节点为左子树的中序遍历结果，个数就是$index个，树根右侧节点为右子树中序遍历的结果。
- 在前序遍历中树根后面$index个元素就是左子树前序遍历的节点，剩余的是右子树前序遍历的节点。
- 递归终止条件，$inorder为空，不能是$preorder为空。【原因未知】

### 性能
执行用时 :108 ms, 在所有 PHP 提交中击败了38.71%的用户
内存消耗 :311.4 MB, 在所有 PHP 提交中击败了17.39%的用户

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
        if (empty($inorder)) return null;
        
        $root = new TreeNode($preorder[0]);
        $index = array_search($preorder[0], $inorder);

        $root->left = $this->buildTree(array_slice($preorder, 1, $index + 1), array_slice($inorder, 0, $index));
        $root->right = $this->buildTree(array_slice($preorder, $index + 1), array_slice($inorder, $index + 1));
        
        return $root;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/python-di-gui-xiang-jie-by-jalan/162793](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/python-di-gui-xiang-jie-by-jalan/162793)
[https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/python-di-gui-xiang-jie-by-jalan/](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/python-di-gui-xiang-jie-by-jalan/)