### 解题思路
采用二分法思想，用递归构造树
算法：
0、定义首位指针$front和$rear。
1、如果$front > $rear就返回空节点。
2、计算中间位置$mid, 获取对应的值赋给一个新节点。

获取中间位置两种方法，第一种个人认为更直观
```
// 第一种
$mid = floor(($front + $rear) / 2);
// 第二种
$mid = $front + floor(($rear - $front) / 2);
```

3、根据中间节点把数组一分为二，左边的数据递归构造左子树，右边的数据递归构造右子树

**注意：单次执行输出的结果可能跟预期不一致，检查是否满足二叉搜索树即可。因为本身就有多种可能，预期只是一种可能。**
输入
[-10,-3,0,5,9]
输出[0,-10,5,null,-3,null,9]
预期[0,-3,9,-10,null,5]

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
     * @param Integer[] $nums
     * @return TreeNode
     */
    function sortedArrayToBST($nums) {
        // 定义变量在赋值严重影响性能 $len = count($nums) - 1;
        return $this->buildBST($nums, 0, count($nums) - 1);
    }

    public function buildBST($nums, $front, $rear)
    {
        if ($front > $rear) {
            return null;
        }

        $mid = floor(($front + $rear) / 2);
        // 很多人喜欢下面的写法，个人认为上面的写法更好理解
        //$mid = $front + floor(($rear - $front) / 2);
        $node = new TreeNode($nums[$mid]);
        $node->left  = $this->buildBST($nums, $front, $mid - 1);
        $node->right = $this->buildBST($nums, $mid + 1, $rear);

        return $node;
    }
}
```