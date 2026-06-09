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
    private $newHead;
    /**
     * @param ListNode $head
     * @return ListNode
     */
    function reverseList($head) {
        $this->newHead = new ListNode(0);
        $temp = $this->newHead;
        $this->dfs($head);
        return $temp->next;
    }

    function dfs($head) {
        if(empty($head)) {
            return ;
        }
        $this->dfs($head->next);
        $head->next = null;
        $this->newHead->next = $head;
        $this->newHead = $this->newHead->next;
    }
}
```