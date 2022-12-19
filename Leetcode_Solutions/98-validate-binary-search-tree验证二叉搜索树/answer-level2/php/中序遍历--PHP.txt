### 解题思路
中序遍历后，检查是否是严格升序。中序遍历完后，还需要遍历检查一次。

注：检查是否升序，不能简单使用sort, 因为[1, 1]这种情况避免不了。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了85.71%的用户
内存消耗 :17.9 MB, 在所有 PHP 提交中击败了5.55%的用户

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
     * @param TreeNode $root
     * @return Boolean
     */
    function isValidBST($root) {
        $res = [];
        $this->task($root, $res);
        
        for ($i = 0; $i < count($res) - 1; $i++) {
            if ($res[$i] >= $res[$i + 1]) return false;
        }

        return true;
    }
    
    public function task($node, &$res)
    {
        if ($node == null) {
            return $res;
        }
        $this->task($node->left, $res);
        $res[] = $node->val;
        $this->task($node->right, $res);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 说明
不能在中序遍历的过程中检查，二叉搜索树要求是当前节点下全部左节点，或全部右节点。

以下为错误代码
错误case: [5,1,4,null,null,3,6]
```
class Solution {

    /**
     * @param TreeNode $root
     * @return Boolean
     */
    function isValidBST($root) {
        $res = [];
        if ($this->task($root, $res) === false)
            return false;
        else 
            return true;
    }
    
    public function task($node, &$res)
    {
        if ($node == null) {
            return $res;
        }
        $this->task($node->left, $res);
        if ($node->val < end($res)) return false;
        $res[] = $node->val;
        $this->task($node->right, $res);
    }
}
```
