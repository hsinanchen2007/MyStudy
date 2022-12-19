```
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
    public function addTwoNumbers($l1, $l2)
    {
        $res = new ListNode(0);
        $sum = $l1->val + $l2->val;
        $carry = floor($sum / 10);
        $sum = $sum % 10;
        $res->val = $sum;
        $now = &$res->next; // 核心操作
        $l1 = $l1->next;
        $l2 = $l2->next;
        // 都不为空
        while ($l1 && $l2) {
            $sum = $l1->val + $l2->val + $carry;
            $carry = floor($sum / 10);
            $sum = $sum % 10;
            $index = new ListNode($sum);
            $now = $index;
            $now = &$index->next;
            $l1 = $l1->next;
            $l2 = $l2->next;
        };
        // l1不为空
        while ($l1) {
            $sum = $l1->val + $carry;
            $carry = floor($sum / 10);
            $sum = $sum % 10;
            $index = new ListNode($sum);
            $now = $index;
            $now = &$index->next;
            $l1 = $l1->next;

        }
        // l2不为空
        while ($l2) {
            $sum = $l2->val + $carry;
            $carry = floor($sum / 10);
            $sum = $sum % 10;
            $index = new ListNode($sum);
            $now = $index;
            $now = &$index->next;
            $l2 = $l2->next;
        }
        // 最后的进位
        if ($carry) {
            $now = new ListNode(1);
        }

        return $res;
    }
    

}
```
