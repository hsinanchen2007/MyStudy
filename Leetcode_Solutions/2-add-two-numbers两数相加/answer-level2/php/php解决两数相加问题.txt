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
    function addTwoNumbers($l1, $l2) {
        $flag = 0;
        $l3 = new ListNode(0);
        $p3 = $l3;
        $i=0;
        while ($l1 != NULL || $l2 != NULL) {
            $s1 = ($l1 != null) ? $l1->val : 0;
            $s2 = ($l2 != null) ? $l2->val : 0;
            $s = $s1 + $s2 + $flag;
            //进位标识
            $flag = $s > 9 ? 1 : 0;
            $p3->next = new ListNode($s % 10);
            $p3 = $p3->next;
            if ($l1 != null) {
                $l1 = $l1->next;
            }
            if ($l2 != null) {
                $l2 = $l2->next;
            }
        }
        //如果最大位数相加大于1则进1
        if ($flag > 0) {
            $p3->next = new ListNode($flag);
        }
        return $l3->next;
    }
}
```
比较中规中矩的做法，评论中没怎么看到Php的就写一下