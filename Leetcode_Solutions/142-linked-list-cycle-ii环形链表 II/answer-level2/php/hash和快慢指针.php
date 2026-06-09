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
     //两种方式。一种hash，一种快慢指针
    /*function detectCycle($head) {
        if($head==null || $head->next==null){
            return false;
        }
        $arrV=[];
        //hash存储
        $node = $head;
        while ($node != null) {
            if(in_array($node,$arrV)){
                return $node;
            }
            $arrV[]=$node;
            $node = $node->next;
        }

        return false;

    }*/
    //快慢指针
    function detectCycle($head) {
        if($head==null || $head->next==null){
            return false;
        }
        $slow=$head;
        $fast=$head;

        while (true) {
            if($fast==null || $fast->next==null){
                break;
            }
            $slow=$slow->next;
            $fast=$fast->next->next;
            if($slow==$fast){
                break;
            }
        }

        $fast=$head;
        while($slow!=$fast){
            $fast=$fast->next;
            $slow=$slow->next;
        }
        return $fast;

    }

}
```