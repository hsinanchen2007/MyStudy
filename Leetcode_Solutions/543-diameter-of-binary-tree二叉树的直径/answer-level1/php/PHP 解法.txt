直接上代码

```php
class Solution
{
    protected $result = 0;
    /**
     * @param TreeNode $root
     * @return Integer
     */
    function diameterOfBinaryTree($root)
    {
        $this->depth($root);
        return $this->result;
    }

    // 递归函数的含义，找出以当前节点为根节点的子树的最大深度
    private function depth($node)
    {
        if ($node === null) return 0;
        $leftDepth = $this->depth($node->left);
        $rightDepth = $this->depth($node->right);
        $this->result = max($this->result, $leftDepth + $rightDepth);
        return max($leftDepth, $rightDepth) + 1;
    }
}
```
