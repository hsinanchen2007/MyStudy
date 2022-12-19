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
    function reverseList($head) {
        if($head==null || $head->next==null){
            return $head;
        }
        $pre=null;
        $next=null;
        $cur=$head;
        while($cur!=null){
            $temp=$cur->next;
            $cur->next=$pre;
            $pre=$cur;
            $cur=$temp;
            
        }
        return $pre;
    }
}
```