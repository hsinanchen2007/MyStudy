#### 理解关键：

根据BST的原理：该二叉搜素树，按照中序遍历是一个递增的数据；

所以：只需要比较<font size:20 color:"red"> 相邻结点 </font>的大小就可以。因为如果不是相邻，差值会更大。

但是，如果只是，根结点跟左右子节点比较的话，测试用例是过不了的。因为这样比较是跳着比较的。例如：中序遍历后是，1，2，3，4，5，6

那么就会只比较2->1, 2->3 和 5->4, 5->6。中间没有比较3->4。


```
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
     * @return Integer
     */
    public $pre = -100;
    public $min = 100;

    function minDiffInBST($root) {
        $this->minBst($root);
        return $this->min;
    }
    
    function minBst($root) {
        if ($root == null) {
            return;
        }
        
        $this->minBst($root->left);
        $this->min = min($this->min, $root->val - $this->pre);
        $this->pre = $root->val;
        $this->minBst($root->right);
        return;
    }
}
```

这里说明下，pre的初始值为绝对值大于100的就可以。因为，题目中，给定树的大小100.如果小于100.就会出现初始值为最小的情况。
