### 解题思路
快慢的原理，快的到头，则慢的一定在中间

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
    function middleNode($head) {
        $slow = $head;
        $fast = $head;

        while($fast->next!=null){
            $slow = $slow->next;
            $fast = $fast->next->next;
        }

        return $slow;


    }
}
```