### 解题思路
先遍历一遍链表，节点元素入栈，之后新构建一个链表，按出栈顺序依次添加列表元素。使用了两次循环，需要优化。

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
        $dataStack = [];
        if($head->next == null) {
            return $head;
        }

        do{
            $dataStack[] = $head->val;
            $head = $head->next;
        }while($head !== null);
        
        $temp = $new = new ListNode(array_pop($dataStack));
        while(!empty($dataStack)) {
            $val = new ListNode(array_pop($dataStack));
            $temp->next = $val;
            $temp = $temp->next;
        }

        return $new;
    }
}
```