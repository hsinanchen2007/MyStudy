### 解题思路
此处撰写解题思路
涉及要点简单概括下：1、计算边界：9+9+1 = 19, 0+0+1=1，需要一个carry进位标志，取值0或1
                  2、循环结束标志：$l1,$l2的当前节点值以及carry标志位。(PS:do while 和while区别)
                  3、PHP结构体_zval_struct的以及PHP相关赋值以及引用
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
        $resLN = null;
        //进位
        $carry = 0;

        while ($l1 || $l2 || $carry) {
            $res = $l1->val + $l2->val + $carry;
            if ($res >= 10) {
                $res -= 10;
                $carry = 1;
            } else {
                $carry = 0;
            }

            $tmpLN = new ListNode($res);
            if (is_null($resLN)) {
                $resLN = $tmpLN;
            } else {
                $next->next = $tmpLN;
            }
            $next = $tmpLN;
            $l1 = $l1->next;
            $l2 = $l2->next;
        }
        return $resLN;
    }
}
```