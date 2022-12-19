### 解题思路
两个指针遍历

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了89.79%的用户
内存消耗 :15.2 MB, 在所有 PHP 提交中击败了6.70%的用户

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
        $dummy_head = new ListNode(0);
        $cur = $dummy_head;
        $carry = $sum = 0;
        while ($l1 != null || $l2 != null) {
            $val1 = $l1 != null ? $l1->val : 0;
            $val2 = $l2 != null ? $l2->val : 0;
            $sum = $val1 + $val2 + $carry;
            $cur->next = new ListNode($sum % 10);
            $cur = $cur->next;
            $carry = intval($sum / 10);
            $l1 = $l1->next;
            $l2 = $l2->next;
        }

        if ($carry > 0) {
            $cur->next = new ListNode($carry);
        }

        return $dummy_head->next;
    }
}
```

参考：
[官方解题](https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode/)