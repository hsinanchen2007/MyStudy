### 解题思路
循环实现单链表反转
循环体：  当前node 指向preNode , 当前node 移动到下一个节点 ，preNode移动承当前节点，注意初始preNode = null，注意记录currentNode->next值。防止下一节点信息丢弃。
终止条件： currentNode 是NULL 循环结束 
反转后的第一个节点是链表的最后一个节点，即为循环后的preNode. 

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
        $preNode = null;
        $currentNode = $head;
        while($currentNode)
        {
            $remainNode = $currentNode->next;
            $currentNode->next = $preNode;
            $preNode = $currentNode;
            $currentNode = $remainNode;
        }
        return $preNode;
    }
}
```