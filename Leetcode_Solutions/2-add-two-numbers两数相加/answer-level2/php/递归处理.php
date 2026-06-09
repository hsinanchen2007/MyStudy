### 解题思路
先处理$l1->next和$l2->next相加的结果。
然后再处理$l1和$l2相加的结果，如果该结果超过10，则处理进位问题。

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
    function addTwoNumbers($l1, $l2) {
        if($l1 == null){
            return $l2;
        }
        if($l2 == null){
            return $l1;
        }

        $node = $this->addTwoNumbers($l1->next, $l2->next);

        $val = $l1->val + $l2->val;
        if($val < 10){
            $first = new ListNode($val);
            $first->next = $node;
            return $first;
        }else{  //进位
            $first = new ListNode($val-10);

            if($node != null){
                $first->next = $node;
                $node->val += 1;

                $curr = $node;
                while($curr->val == 10){
                    $curr->val = 0;
                    if($curr->next != null){
                        $curr->next->val += 1;
                    }else{
                        $curr->next = new ListNode(1);
                    }
                    $curr = $curr->next;
                }

                return $first;
            }else{
                $first->next = new ListNode(1);
                return $first;
            }
        }
    }
}











```