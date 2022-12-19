### 解题思路
此处撰写解题思路
核心点就是弄清楚，比较的两个node；我的处理方式是比较前一位和当前位
首先判断当前位的val是否等于前一个的val，如果相等，则删除当前节点。否则，重新赋值
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
    function deleteDuplicates($head) {
        //前面的node和当前的node
        $preNode = $head;
        $nextNode = $head->next;
        while ($nextNode) {
            if ($preNode->val == $nextNode->val) {
                $nextNode = $nextNode->next;
                $preNode->next = $nextNode;
            } else {
                $preNode = $nextNode;
                $nextNode = $nextNode->next;
            }
        }
        return $head;
    }
}
```