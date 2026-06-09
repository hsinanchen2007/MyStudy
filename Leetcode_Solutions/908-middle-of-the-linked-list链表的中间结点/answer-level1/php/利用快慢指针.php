### 解题思路
利用快慢指针
```
执行用时 :4 ms, 在所有 PHP 提交中击败了96.97%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了73.33%的用户
```
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
        // 利用快慢指针
        $fast = $slow = $head;
        while($fast != NULL && $fast->next != NULL) {
            $fast = $fast->next->next;
            $slow = $slow->next;
        }
        return $slow;
    }
}
```