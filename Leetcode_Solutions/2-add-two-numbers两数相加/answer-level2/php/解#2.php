### 解题思路
加入了php7的？？运算，并使用do while优化执行用时

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
        $listNode = new ListNode(0);
        $l = $listNode;
        $carry = 0;

        do{

            $v1 = $l1->val ?? 0;//if $l1->val not set then set to 0
            $v2 = $l2->val ?? 0;//if $l2->val not set then set to 1
            $res = $v1 + $v2 + $carry;
            $carry = floor($res/10);      
    
            $l->next = new ListNode($res%10);//set the next node's val to be the remainder
            $l = $l->next;//shift to next node
            $l1 = $l1->next;
            $l2 = $l2->next;
        }while ($l1 || $l2 || $carry);

        return $listNode->next;
    }
}
```