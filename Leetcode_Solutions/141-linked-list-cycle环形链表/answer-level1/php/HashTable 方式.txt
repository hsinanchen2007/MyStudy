### 解题思路
hash 方法，存储节点引用，如果遍历到最后一个节点，还没有发现有节点出现在hash表中，那么就说明这个链表没有环，否则，有环

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
        $hashMap = [];
        $curr = $head;
        while($curr !== null && $curr->next !== null) {
            if(in_array($curr, $hashMap)) return true;
            $hashMap[] = $curr;
            $curr = $curr->next;
        }
        return false;
    }
}
```