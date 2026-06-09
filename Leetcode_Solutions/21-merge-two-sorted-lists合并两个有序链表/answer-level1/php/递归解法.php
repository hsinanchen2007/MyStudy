### 解题思路
整体思路：
    1. l1 为空时，结束递归，返回l2
    2. l2 为空时，结束递归，返回l1
    3. l1->val < l2->val 以l1作为头节点，继续递归
    4. l1->val >= l2->val 以l2作为头节点，继续递归
    
细节：
    1. 上述4个条件，1&2是必须要在3&4之前进行判断的;
    2. l1->val < l2->val的时候：我们要以l1作为头节点，进行递归，
       递归的入参是：l1->next & l2，因为我们需要知道l1->next和l2的比较结果，此次递归的结果，作为l1->next的值；
    3. l1->val >= l2->val 同上。

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
    function mergeTwoLists($l1, $l2) {
        if($l1 === null) {
            return $l2;
        } else if($l2 === null) {
            return $l1;
        } else if($l1->val < $l2->val) {
            $l1->next = $this->mergeTwoLists($l1->next, $l2);
            return $l1;
        } else {
            $l2->next = $this->mergeTwoLists($l1, $l2->next);
            return $l2;
        }
    }
}