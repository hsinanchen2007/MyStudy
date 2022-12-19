### 解题思路
先封装一个函数，将链表分割为三部分：中间节点，左侧头结点，右侧头结点。
然后递归调用sortedListToBST即可。

### 代码

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
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
     * @param ListNode $head
     * @return TreeNode
     */
    function sortedListToBST($head) {
        if($head == null){
            return null;
        }
        if($head->next == null){
            return new TreeNode($head->val);
        }

        list($left, $top, $right) = $this->cutList($head);

        $left = $this->sortedListToBST($left);
        $right = $this->sortedListToBST($right);

        $root = new TreeNode($top->val);
        $root->left = $left;
        $root->right = $right;

        return $root;
    }

    function cutList($head){
        if($head->next == null){
            return array(null, $head, null);
        }
        if($head->next->next == null){
            $h = $head->next;
            $head->next = null;
            return array($head, $h, null);
        }
        
        $slow = $head;
        $fast = $head;
        $tail = $head;
        while($fast && $fast->next){
            $tail = $slow;
            $slow = $slow->next;
            $fast = $fast->next->next;
        }
        $tail->next = null;
        $h = $slow->next;
        $slow->next = null;

        return array($head, $slow, $h);
    }
}




















```