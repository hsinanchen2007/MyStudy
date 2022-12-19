### 解题思路
第一次尝试没有用链表而是数学转换，所以导致溢出。第二次尝试感谢[@shao-nao](/u/shao-nao/)的解答提示，终于解出。
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
        $final_result = null;
        //进位
        $carry = 0;

        while ($l1 || $l2 || $carry) {
            $cur_pos_result = $l1->val + $l2->val + $carry;//当前位数计算结果
            if ($cur_pos_result >= 10) {
                $cur_pos_result -= 10;//超出10则减10，并进位为1，加入下一位的运算中
                $carry = 1;
            } else {
                $carry = 0;
            }

            $temp = new ListNode($cur_pos_result);
            if (is_null($final_result)) {
                $final_result = $temp;
            } else {
                $next->next = $temp;
            }
            $next = $temp;
            $l1 = $l1->next;
            $l2 = $l2->next;
            // print_r($temp);
            // print_r($final_result);
        }
        return $final_result;
    }
}
```