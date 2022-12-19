### 解题思路
主要的思路在于要加入前置节点

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
     * @param Integer $val
     * @return ListNode
     */
    function removeElements($head, $val) {
        $sentinel = new ListNode(0);
        $sentinel->next = $head;
        $curr = $head;
        $prev = $sentinel;

        while($curr != null){
            if($curr->val == $val){
                $prev->next = $curr->next;
            } else {
                $prev = $curr;
            }

            $curr = $curr->next;
        }

        return $sentinel->next;
    }
}
```