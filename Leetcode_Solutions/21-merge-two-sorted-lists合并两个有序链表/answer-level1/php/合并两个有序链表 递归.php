### 解题思路
遵循递归的思想
1. 递归终止条件
2. 分而治之
3. 返回数据

不要刻意的去追踪递归，只要处理好当前应该有的结果进行返回即可。

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
     * 递归方式合并两个有序链表
     *
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function mergeTwoLists($l1, $l2) {
        
        // 递归结束条件
        if ($l1 == null) return $l2;
        if ($l2 == null) return $l1;

        if ($l1->val < $l2->val) {
            $l1->next = $this->mergeTwoLists($l1->next, $l2);
            return $l1;
        } else {
            $l2->next = $this->mergeTwoLists($l2->next, $l1);
            return $l2;
        }
        
    }
}
```