时间复杂度： O(n)
空间复杂度： O(n)

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
     * @return Integer[]
     */
    function reversePrint($head) {
        $array = [];

        while ($head) {
            $array[] = $head->val;
            $head = $head->next;
        }

        for ($i = 0, $count = count($array), $j = $count - 1; $i < $j; $i++, $j--) {
            $tmp = $array[$i];
            $array[$i] = $array[$j];
            $array[$j] = $tmp;
        }

        return $array;
    }
}
```