### 解题思路
参考官方 PHP版本

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
        $newHead = null;
        $curr = $head;
        while($curr != null){
            $temp = $curr->next;
            $curr->next = $newHead;
            $newHead = $curr;
            $curr = $temp;
        }
        return $newHead;
    }
}
```