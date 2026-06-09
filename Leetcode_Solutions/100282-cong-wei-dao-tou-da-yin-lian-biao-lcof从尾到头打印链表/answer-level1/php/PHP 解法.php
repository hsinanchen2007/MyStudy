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
     * @return Integer[]
     */
    function reversePrint($head) {
        $arr = [];
        while ($head !== null) {
            // 从数组头部添加
            array_unshift($arr, $head->val);
            $head = $head->next;
        }
        return $arr;
    }
}
```