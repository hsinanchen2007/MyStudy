### 解题思路
此处撰写解题思路

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
    function swapPairs($head) {
        if($head==null || $head->next ==null) return $head;
        $dumy = new ListNode(null);
        $dumy->next = $head;
        $prevNode = $dumy;//前驱节点
        while($head!==null && $head->next!==null){
            //应该很好理解 头就是first节点、next是second节点
            $first = $head;
            $second = $head->next;
            
            //将first的next指向second的next
            //类似 1->2->3->4 变成 1->3->4
            $first->next = $second->next;
            //second的next指向first 变成 2->1->3->4
            $second->next = $first;
            //将second指向前驱节点的next
            $prevNode->next = $second;
            //重置前驱节点 1->3->4其实就是当前节点first
            $prevNode = $first;
            //重置head 2-1->3->4 指到 3这个节点开始
            $head = $first->next;
        }
        return $dumy->next; 
    }
}
```