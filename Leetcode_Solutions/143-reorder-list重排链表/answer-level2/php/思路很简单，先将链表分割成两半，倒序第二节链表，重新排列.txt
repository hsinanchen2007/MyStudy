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
     * @return NULL
     */
    function reorderList($head) {
      
        $slow = $head;
        $fast = $head;
        
        while($fast->next != null && $fast->next->next != null){
            $slow = $slow->next;
            $fast = $fast->next->next;
        }
        
        
        $second = $slow->next;
        $slow->next = null;
        
        $pre = null;
        $cur = $second;
        
        while($cur != null){
            $next = $cur->next;
            
            $cur->next = $pre;
            $pre = $cur;
            $cur = $next;
        }
        
        echo $pre->val;
        
        $new = $head;
        
        while($pre != null){
            $nextOne = $new->next;
            $nextTwo = $pre->next;
        
            $new->next = $pre;
            $pre->next = $nextOne;
            
            $new = $nextOne;
            $pre = $nextTwo;
            
        }
        return $head;
        

        
    }
}
```