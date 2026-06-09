
利用如果环形链表，快的必然会追上慢的思路
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
     * @param ListNode $head
     * @return ListNode
     */
    function isCycleList($head) {
        $fast = $head;
        $slow = $head;

        while ($fast != null && $fast->next != null) {
            $fast = $fast->next->next;
            $slow = $slow->next;
            if ($fast === $slow) {
                return true;
            }
        }
        return false;
    }
}
```



