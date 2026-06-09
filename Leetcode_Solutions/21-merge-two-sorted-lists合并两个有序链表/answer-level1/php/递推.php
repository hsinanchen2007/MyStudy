### 解题思路
非常感谢[@z1m](/u/z1m/)的题解

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
    // 递推
    function mergeTwoLists($l1, $l2) {
        if ($l1 == null) {//l1已经走完，返回l2
            return $l2;
        }
        else if ($l2 == null) {//l2已经走完，返回l1
            return $l1;
        }
        else if ($l1->val < $l2->val) {//如果l1 head > l2 head，则l1指向另两个剩余的和
            $l1->next = $this->mergeTwoLists($l1->next, $l2);
            return $l1;
        }
        else {
            $l2->next = $this->mergeTwoLists($l1, $l2->next);
            return $l2;
        }
    }
}
```