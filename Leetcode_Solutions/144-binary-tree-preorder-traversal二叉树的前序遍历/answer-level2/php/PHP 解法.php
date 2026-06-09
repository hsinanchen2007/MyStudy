### 借助一个复制函数，递归实现

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
    function preorderTraversal($root) {
        $result = [];
        $this->traversal($root, $result);
        return $result;
    }

    private function traversal($node, &$result)
    {
        if (is_null($node)) {
            return;
        }

        $result[] = $node->val;
        $this->traversal($node->left, $result);
        $this->traversal($node->right, $result);
    }
}
```

### 迭代解法

从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压右孩子再压左孩子

```php
class Solution
{
    function preorderTraversal($root)
    {
        $stack = new SplStack();
        $res = [];
        $stack->push($root);
        while ($stack->count()) {
            $cur = $stack->pop();
            $res[] = $cur->val;
            if ($cur->right !== null) $stack->push($cur->right);
            if ($cur->left !== null) $stack->push($cur->left);
        }

        return $res;
    }
}
```

