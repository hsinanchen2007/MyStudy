时间复杂度： O(n)
空间复杂度： O(1)

```php
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
    function middleNode($head) {
        $l = $head;
        $r = $head;
        while ($r != null && $r->next != null) {
            $l = $l->next;
            $r = $r->next->next;
        }

        return $l;
    }
}
```