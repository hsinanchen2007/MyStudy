先计算出链表的长度，然后再去打印链表

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
     * @param Integer $k
     * @return ListNode
     */
    function getKthFromEnd($head, $k) {
        if (empty($head)) {
            return null;
        }

        $len = 0;
        $pre = $head;
        while ($pre->next) {
            $pre = $pre->next;
            $len++;
        }

        for ($i = 0; $i < ($len - $k + 1); $i++) {
            $head = $head->next;
        }

        return $head;
    }
}
```
