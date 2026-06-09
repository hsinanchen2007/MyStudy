### 解题思路
链表反转，记录前一个节点，将当前节点的next指向pre节点

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
    function reverseList($head) {
        $curr = $head;
        $pre = null;
        while($curr != null) {
            $tmp = $curr->next;
            $curr->next = $pre;
            $pre = $curr;
            $curr = $tmp;
        }
        return $pre;
    }
}
```