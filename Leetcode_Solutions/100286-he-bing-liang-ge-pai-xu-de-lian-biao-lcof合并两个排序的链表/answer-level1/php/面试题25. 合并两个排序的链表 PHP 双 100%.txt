### 解题思路
1. 开一个新链表
2. 两条链表都没遍历完：谁小谁从后面接上去
3. 其中一条完了：另外一条接上去

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
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function mergeTwoLists($l1, $l2) {
        $i = 0;
        $j = 0;

        // 开一条新链表
        $res = new ListNode(0);
        $head = $res;

        while($l1 != null && $l2 != null) {
            
            // 谁小谁接上去
            if($l1->val < $l2->val) {
                $res->next = new ListNode($l1->val);
                $l1 = $l1->next;
            }
            else { 
                $res->next = new ListNode($l2->val);
                $l2 = $l2->next;
            }

            $res = $res->next;
        }

        // 谁没完谁接上去
        while($l1 != null) {
            $res->next = new ListNode($l1->val);
            $l1 = $l1->next;
            $res = $res->next;
        }

         while($l2 != null) {
            $res->next = new ListNode($l2->val);
            $l2 = $l2->next;
            $res = $res->next;
        }

        return $head->next;
    }
}
```