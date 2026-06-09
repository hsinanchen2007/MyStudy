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
     * @param Integer $val
     * @return ListNode
     */
    function deleteNode($head, $val) {
        $dummyHead = new ListNode(null);
        $dummyHead->next = $head;
        $temp = $dummyHead;
        while($dummyHead->next) {
            if($dummyHead->next->val === $val) {
                $dummyHead->next = $dummyHead->next->next;
                break;
            }
            $dummyHead = $dummyHead->next;
        }
        return $temp->next;
    }
}
```