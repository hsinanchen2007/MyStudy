### 解题思路
参考无的放矢的解题思路，并添加了备注。

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
        return $this->add($l1, $l2, 0);
    }

    function add($l1, $l2, $jinwei) {
        //计算两数相加后的个位
        $sum = new ListNode(($l1->val + $l2->val + $jinwei) % 10);
        //计算两数相加后是否大于10，是则进1，否则进0
        $jinwei = floor(($l1->val + $l2->val + $jinwei) / 10);

        if ($l1->next || $l2->next || $jinwei) {
            //l1和l2的next都有可能是null，如果是null就给个0
            if (is_null($l1->next)) {
                $l1->next = new ListNode(0);
            }
            if (is_null($l2->next)) {
                $l2->next = new ListNode(0);
            }
            $sum->next = $this->add($l1->next, $l2->next, $jinwei);
        }

        return $sum;
    }
}
```