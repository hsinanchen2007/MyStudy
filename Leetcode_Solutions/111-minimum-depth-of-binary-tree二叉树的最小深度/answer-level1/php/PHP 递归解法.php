一定要理解递归函数的含义，具体在当前递归层级做了些什么，其他的不用考虑

```php
class Solution
{
    function minDepth($root)
    {
        if ($root === null) return 0;
        if ($root->left === null && $root->right === null) return 1;
        $min = PHP_INT_MAX;
        if ($root->left !== null) $min = min($this->minDepth($root->left), $min);
        if ($root->right !== null) $min = min($this->minDepth($root->right), $min);
        return $min + 1;
    }
}
```
