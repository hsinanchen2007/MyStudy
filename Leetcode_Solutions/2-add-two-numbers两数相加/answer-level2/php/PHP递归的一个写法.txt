### 解题思路
既然用了链表，很可能是因为长度问题而不能直接计算，所以排除把数据取出来相加再放到链表的方法
层层相加最好用递归来实现，以$l1为基准当作结果链表，把$l2加上来，
只要两者有一个有值就相加
只要两者有一个有下级，就递归
输入参数是两个链表及是否满10，满10就进位
返回参数就一个结果$l1即可

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
        return $this->recurision($l1,$l2);
    }
    function recurision($l1, $l2, $plus = false) {
        if ($l1 && $l2) {
            $sum = $l1->val + $l2->val;
            if ($plus) {
                $plus = false;
                $sum += 1;
            }
            if ($sum > 9) {
                $sum = $sum -10;
                $plus = true;
            }
            $l1->val = $sum;
        } else {
            if ($l2 && !$l1) {
                $l1 = clone $l2;
                $l1->next = null;
            }
            if ($plus) {
                $plus = false;
                $l1->val += 1;
            }
            if ($l1->val > 9) {
                $plus = true;
                $l1->val = 0;
             }
        }
        if ($l1->next or $l2->next) {
            $l1->next = $this->recurision($l1->next, $l2->next, $plus);
        } else {
            if ($plus) {
                $next = clone $l1;
                $next->next = null;
                $next->val = 1;
                $l1->next = $next;
            } else 
                $l1->next = null;
            
        }
        return $l1;
    }
}
```