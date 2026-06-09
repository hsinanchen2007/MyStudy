```
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
        // 初始化前一个节点为空
        $pre = null;
        // 初始化当前节点为 $head
        $curr = $head;
        // 循环遍历，当前节点为 null 时结束遍历
        while ($curr != null) {
            // 保存当前节点的下一个节点
            $tmp = $curr->next;
            // 将当前节点的next改为指向前一个结点
            $curr->next = $pre;
            // 将当前节点保存到 $pre 中
            $pre = $curr;
            // 将当前节点的下一个节点赋值给当前节点
            $curr = $tmp;
        }
        // 返回新的头节点
        return $pre;
        
    }
}
```
