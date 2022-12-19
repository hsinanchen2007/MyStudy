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
     * @param Integer $k
     * @return ListNode
     */
    function getKthFromEnd($head, $k) {
        $l = $head;
        $r = $head;

        while ($r) {
            $r = $r->next;
            $k > 0 ? $k-- : $l = $l->next;
        }

        return $l;
    }
}
```