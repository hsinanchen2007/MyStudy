    新建一个链表，存储每次相加之和，若某一个链表不存在节点，只遍历另外一个链表。
    注意点：
    1、每次相加要计算溢出值
    2、循环完成后，也许是存在溢出值，需要单独处理（如，1 | 9。答案是0,1 需单独判断处理是否需添加一个节点）


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
            $newHead = null;
            $data = 0;
            while ($l1 != null || $l2 != null) {
                $sum = $data;
                if ($l1 != null) {
                    $sum += $l1->val;
                    $l1 = $l1->next;
                }
                if ($l2 != null) {
                    $sum += $l2->val;
                    $l2 = $l2->next;
                }

                if ($sum >= 10) {
                    $sum -= 10;
                    $data = 1;
                } else {
                    $data = 0;
                }

                if ($newHead == null) {
                    $tmp = $newHead = new ListNode($sum);
                } else {
                    $tmp->next = new ListNode($sum);
                    $tmp = $tmp->next;
                }
            }
            if ($data > 0) {
                $tmp->next = new ListNode(1);
            }
            return $newHead;
        }
    }