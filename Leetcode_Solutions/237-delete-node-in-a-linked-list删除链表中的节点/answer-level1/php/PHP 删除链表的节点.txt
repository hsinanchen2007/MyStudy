知道上一个节点，改一下上一个节点的next即可，但是因为不知道上一个节点，
所以换个思路，把当前节点变成下一个节点，也可实现删除节点。
```
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
class Solution {

    /**
     * @param ListNode $node
     */
    function delete($node) {
        $node->val = $node->next->val;
        $node->next= $node->next->next;
    }
}
```