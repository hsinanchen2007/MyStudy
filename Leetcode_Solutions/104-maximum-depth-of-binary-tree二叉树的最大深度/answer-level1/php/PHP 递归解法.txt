理解了递归函数的定义，代码写起来就不难

```php
function maxDepth($root)
{
    if ($root === null) return 0;
    $left = $this->maxDepth($root->left);
    $right = $this->maxDepth($root->right);
    return max($left, $right) + 1;
}
```
