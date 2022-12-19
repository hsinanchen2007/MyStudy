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
     * @param ListNode $head
     * @return ListNode
     */
    function swapPairs($head) {
        // dummy cur cur->next cnext->next
        $dummy = new ListNode(null);
        $dummy->next = $head;
        $this->_swap($head, $dummy);
        return $dummy->next;
    }

    function _swap($cur, $pre) {
        if ($cur === null || $cur->next === null) {
            return $cur;
        }
        $cnext = $cur->next;
        $cur->next = $cnext->next;
        $cnext->next = $cur;
        $pre->next = $cnext;
        $pre = $cur;
        $cur = $cur->next;
        $this->_swap($cur, $pre);
    }
}
```