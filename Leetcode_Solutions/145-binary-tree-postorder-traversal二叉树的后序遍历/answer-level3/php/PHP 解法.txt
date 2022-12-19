### 解题思路
前序遍历和中序遍历的难度都是中等，不明白为什么后序遍历为困难

### 递归解法

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
     * @return Integer[]
     */
    function postorderTraversal($root) {
        $result = [];
        $this->traversal($root, $result);
        return $result;
    }

    private function traversal($node, &$result)
    {
        if (is_null($node)) {
            return;
        }

        $this->traversal($node->left, $result);
        $this->traversal($node->right, $result);
        $result[] = $node->val;
    }
}
```

### 迭代解法
参考官方题解：从根节点开始依次迭代，弹出栈顶元素输出到输出列表中，然后依次压入它的所有孩子节点，按照从上到下、从左至右的顺序依次压入栈中。
因为深度优先搜索后序遍历的顺序是从下到上、从左至右，所以需要将输出列表逆序输出。

```php
class Solution
{
    function postorderTraversal($root)
    {
        $stack = new SplStack();
        $res = [];
        if ($root === null) return $res;
        $stack->push($root);

        while ($stack->count()) {
            $cur = $stack->pop();
            array_unshift($res, $cur->val);
            if ($cur->left !== null) $stack->push($cur->left);
            if ($cur->right !== null) $stack->push($cur->right);
        }

        return $res;
    }
}
```
