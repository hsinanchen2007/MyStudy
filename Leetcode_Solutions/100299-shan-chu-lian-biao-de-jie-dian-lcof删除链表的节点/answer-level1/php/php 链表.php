### 解题思路


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
    function deleteNode($head, $val) {
        $curr = $head;
        if($head->val == $val){
            return $head->next;
        }
        while($curr != null && $curr->next !=null){
            if($curr->next->val == $val){
                $curr->next = $curr->next->next;
            }else{
                $curr = $curr->next;
            }
        }

        return $head;
    }
}
```