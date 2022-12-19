### 解题思路
此处撰写解题思路

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
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function mergeTwoLists($l1, $l2) {
        // 利用哨兵简化代码的难度
        $node = new ListNode(null);
        $pre = $node;
        while ($l1 != null && $l2 != null) {
            if ($l1->val < $l2->val) {
                $pre->next = $l1;
                $l1 = $l1->next;
            } else {
                $pre->next = $l2;
                $l2 = $l2->next;
            }
            $pre = $pre->next;
        }

        if ($l1 == null) $pre->next = $l2;
        if ($l2 == null) $pre->next = $l1;

        return $node->next;
    }
}
```