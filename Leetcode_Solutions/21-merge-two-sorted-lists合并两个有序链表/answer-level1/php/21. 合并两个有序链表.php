### 解题思路
1. 递归思路实现
2. 何时终止：当 l1 为空或 l2 为空时结束
3. 返回值：每一层调用都返回排序好的链表头
4. 本级递归处理：如果 l1.val 值更小，则将 l1.next 与排序好的链表头相接，l2 同理
5. O(m+n)，mm 分别为 l1、l2 的长度

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
        if(empty($l1)) return $l2;
        if(empty($l2)) return $l1;

        if($l1->val < $l2->val){
            $l1->next = $this->mergeTwoLists($l1->next, $l2);
            return $l1;
        } else {
            $l2->next = $this->mergeTwoLists($l1, $l2->next);
            return $l2;
        }
    }
}
```