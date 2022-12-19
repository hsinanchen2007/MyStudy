### 解题思路
### 递归方式
1. 找到终止条件倒数第二个 node.next == null ，也就是说代码运行到后面最后的一个元素是倒数第二个
2. 让倒数第一个得指针指向倒数第二个 node.next.next = node
3. 倒数第二个得指针指向 node.next = null

### 迭代方式
**其实就是指针的方向变了** `cur=当前数据集，pre=上一个数据集` 迭代前 data->next 迭代后 next<-data
1. cur 的节点指针指向 pre
2. pre = cur
3. cur = next
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
     * 递归方式
     *
     * @param ListNode $head
     * @return ListNode
     */
    function reverseList($head) {
        // 倒数第二个元素截止
        if ($head == null || $head->next == null) return $head;
        $pre = $this->reverseList($head->next);
        $head->next->next = $head;
        $head->next = null;
        return $pre;
    }

    /**
     * 迭代方式
     *
     * @param ListNode $head
     * @return ListNode
     */
    function reverseList1($head) {
        $cur = $head; $pre = null;
        while ($cur != null) {
            $next = $cur->next;
            // 将当前指针设置为 pre
            $cur->next = $pre;
            // 上一个node=当前元素
            $pre = $cur;
            // 当前 node=next
            $cur = $next;
        }
        return $pre;
    }
}
```