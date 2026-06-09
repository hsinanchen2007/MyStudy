### 解题思路
如果在hashMap中找到某个节点，表明是有环链表，那么返回那个节点即可。

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
    function detectCycle($head) {
        $hashMap = [];
        $curr = $head;
        while($curr) {
            $key = array_search($curr, $hashMap);
            if($key !== false) return $curr;
            $hashMap[] = $curr;
            $curr = $curr->next;
        }
        return false;
    }
}
```