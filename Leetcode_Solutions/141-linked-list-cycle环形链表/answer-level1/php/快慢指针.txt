### 解题思路
1. slow为慢指针，fast为快指针；
2. 循环结束条件是直到fast指向null，这表明该链表是无环链表；
3. 循环内部，slow指针，每次往前走一步，fast指针每次往前走两步，走啊走，走啊走，如果fast走完原来的链表，又来到了slow的身边，那么说明，这个链表是有环链表。

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
     * @return Boolean
     */
    function hasCycle($head) {
        // 快慢指针
        $slow = $head;
        $fast = $head;
        while($fast !== null && $fast->next !== null) {
            $slow = $slow->next;
            $fast = $fast->next->next;
            if($slow === $fast) return true;
        }
        return false;
    }
}
```