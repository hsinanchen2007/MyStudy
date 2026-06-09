### 解题思路
1. 设置previous指向null；
2. 思路是：current->next指向previous，更新previous为current，更新current为current的next（注意：由于node1->node2->node3这种情况下，如果先将node1(current->next=previous)指向其他地方，node2是没办法获取到node1的信息的，所以要保存node1的信息。）

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
    function reverseList($head) {
        $previous = null;
        $current = $head;
        while($current != null) {
            $next = $current->next;
            $current->next = $previous;
            $previous = $current;
            $current = $next;
        }
        return $previous;
    }
}
```