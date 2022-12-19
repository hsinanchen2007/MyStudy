
假设俩单向链表没有环，如果相交，则最后一个节点肯定是相同的
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
     * @param ListNode $headA
     * @param ListNode $headB
     * @return bool
     */
    function isIntersect($headA, $headB) {
        if ($headA == null || $headB == null) {
            return false;
        }

        while ($headA->next !== null) {
            $headA = $headA->next;
        }

        while ($headB->next !== null) {
            $headB = $headB->next;
        }

        return $headA === $headB;
    }
}
```
