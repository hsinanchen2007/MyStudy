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
     * @return Integer
     */
    function getDecimalValue($head) {
        $int = 0;

        while ($head->val !== null) {
            $int = ($int << 1) + $head->val;
            $head = $head->next;
        }

        return $int;
    }
}
```