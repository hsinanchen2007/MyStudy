### 解题思路
遍历原链表，复制结点，改成头插法建立新链表
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
        if($head->next == null)
            return $head;

        $new_head = null;
        while($head)
        {
            $new_node = clone $head;
            $new_node->next = null;

            if($new_node == null)
                $new_head = $new_node;
            else
            {
                $new_node->next = $new_head;
                $new_head = $new_node;
            }
            $head = $head->next;
        }
        return $new_head;
    }
}
```