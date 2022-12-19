### 解题思路
二进制转十进制

### 代码

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
        $res = 0;
        $cur = $head;
        while ($cur != null) {
            $res = $res * 2 + $cur->val;
            $cur = $cur->next;
        }

        return $res;
    }
}
```