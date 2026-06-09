### 解题思路
此处撰写解题思路
正常的排序，此题较为简单，不加赘述
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
        $root = $node = new ListNode(0);
        while ($l1 || $l2) {
            if (!$l1) {
                $node->next = $l2;
                return $root->next;
            }
            if (!$l2) {
                $node->next = $l1;
                return $root->next;
            }
            if ($l1->val <= $l2->val) {
                $node->next = $l1;
                $l1 = $l1->next;
            } else {
                $node->next = $l2;
                $l2 = $l2->next;
            }
            $node = $node->next;
        }
        return $root->next;
    }
}
```