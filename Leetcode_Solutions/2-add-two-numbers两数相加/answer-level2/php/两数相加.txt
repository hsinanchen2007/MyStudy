```
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 * 模拟真实的数据运算
 */
class Solution
{

    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2)
    {
        $carry = 0;//进位
        $head = $cur = new ListNode(0);

        do {
            //数学运算
            $sum = $l1->val + $l2->val + $carry;
            $yushu = $sum % 10;//余数
            $carry = $sum >= 10 ? 1 : 0;

            $cur->next = new ListNode($yushu);
            $cur = $cur->next;

            if($carry==0 && !$l1->next && !$l2->next){//都运算到最后一位，并且没有进位，退出
                break;
            }

            $l1 = $l1->next;
            $l2 = $l2->next;

        } while (true);

        return $head->next;//因为有个头指针head是0，需要去掉
    }
}
```
