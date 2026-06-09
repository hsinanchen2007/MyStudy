
遇到二叉树的结构，第一印象肯定就是递归解法，这道题有个层次($level)的概念，所以层次需要不断的向下传递.

此外，左右节点在同一层，所以肯定是需要和$level一块当成参数传递的；

```php
    function levelOrder($root)
    {
        if ($root == null) {
            return [];
        }

        $res[0][] = $root->val;
        $level = 1;
        $this->helper($root->left, $root->right, $res, $level);
        return $res;
    }

    function helper($left, $right, &$res, $lever)
    {
        if ($left != null || $right != null) {
            if ($left != null) {
                $res[$lever][] = $left->val;
            }
            if ($right != null) {
                $res[$lever][] = $right->val;
            }
            $lever++;
            $this->helper($left->left, $left->right, $res, $lever);
            $this->helper($right->left, $right->right, $res, $lever);
        }
    }
```
