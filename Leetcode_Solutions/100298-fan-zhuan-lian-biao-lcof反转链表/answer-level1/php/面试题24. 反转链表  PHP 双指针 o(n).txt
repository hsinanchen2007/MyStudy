### 解题思路
1. 定义一条新链表，并在头部插入（原有元素的 next = 新列表第一个节点）

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
        $pre = new ListNode($head->val);
        $cur = $head->next;

        while($cur != null) {
            
            $tmp = new ListNode($cur->val);
            $tmp->next = $pre;
            $pre = $tmp;

            $cur = $cur->next;
        }

        return $pre;
    }
}
```