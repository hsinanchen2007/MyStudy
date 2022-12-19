### 递归代码

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
    function inorderTraversal($root)
    {
        $result = [];
        $this->helper($root, $result);
        return $result;
    }

    private function helper($root, &$result)
    {
        if ($root == null) {
            return;
        }

        $this->helper($root->left, $result);
        $result[] = $root->val;
        $this->helper($root->right, $result);
    }
}
```

注意， LeetCode 不支持 PHP7 的变量类型声明，以下代码会报错

```php
private function helper(TreeNode $root, array &$result)
{
    // code
}
```

### 迭代代码

不太好理解 (左根右)
```
//  用p当做指针
//  p = root
//  while p or stack:
//      # 把左子树压入栈中
//      while p:
//          stack.append(p)
//          p = p.left

//      # 输出 栈顶元素
//      p = stack.pop()
//      res.append(p.val)
//      # 看右子树
//      p = p.right
//  return res
```

```php
$stack = new SplStack();
$res = [];
$p = $root;
while ($p !== null || $stack->count()) {
    while ($p !== null) {
        $stack->push($p);
        $p = $p->left;
    }

    if ($stack->count()) {
        $p = $stack->pop();
        $res[] = $p->val;
        $p = $p->right;
    }
}
return $res;
```

