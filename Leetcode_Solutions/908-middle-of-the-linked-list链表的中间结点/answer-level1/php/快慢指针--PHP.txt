### 解题思路
快指针是慢指针的2倍。

### 性能
执行用时 :4 ms, 在所有 php 提交中击败了91.67%的用户
内存消耗 :15.1 MB, 在所有 php 提交中击败了7.41%的用户

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
     * @param ListNode $head
     * @return ListNode
     */
    function middleNode($head) {
        $fast = $slow = $head;
        while ($fast != null && $fast->next != null) {
            $slow = $slow->next;
            $fast = $fast->next->next;
        }

        return $slow;
    }
}
```