先以第一个元素为根节点，遍历数组

题目可知无重复项
接下来的数字只可能比根节点大或小

1. 当比根节点大时，以此节点作为根节点，原根节点作为此节点的左分支
2. 当比根节点小时，从根节点开始遍历根节点右分支，直到找到比此节点小的节点作为此节点左分支，此节点插入其中作为上一节点的右分支
3. 遍历结束即可

时间复杂度为O((1+n)n/2)
空间复杂度O(n)

代码为更加优化的版本，增加了上一节点为缓存，当此元素比上一节点小时，直接插入上一节点右分支，复杂度会更加降低


```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @return TreeNode
     */
    function constructMaximumBinaryTree($nums)
    {
        $prev_node = new TreeNode($nums[0]);
        $root = $prev_node;
        for ($i = 1; $i < count($nums); $i++) {
            $cur_node = new TreeNode($nums[$i]);
            if ($cur_node->val < $prev_node->val) {
                $prev_node->right = $cur_node;
            } else {
                if ($cur_node->val > $root->val) {
                    $cur_node->left = $root;
                    $root = $cur_node;
                } else {
                    $tmp_node = $root;
                    while ($cur_node->val < $tmp_node->right->val) {
                        $tmp_node = $tmp_node->right;
                    }
                    $cur_node->left = $tmp_node->right;
                    $tmp_node->right = $cur_node;
                }
            }
            $prev_node = $cur_node;
        }
        return $root;
    }
}
```