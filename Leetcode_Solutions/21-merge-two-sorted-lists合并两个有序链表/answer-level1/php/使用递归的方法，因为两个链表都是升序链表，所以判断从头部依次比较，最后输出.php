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
        if($l1 == null){
            return $l2;//递归结束条件
        }else if ($l2 == null){
            return $l1;//递归结束条件
        }else{
            //从$l1与$l2的head开始比较。将比较小的链表的下一个节点与另一个链表再次比较
            if($l1->val <= $l2->val){
                $l1->next = $this->mergeTwoLists($l1->next,$l2);
                return $l1;
            }else{
                $l2->next = $this->mergeTwoLists($l2->next,$l1);
                return $l2;
            }
        }
    }
}