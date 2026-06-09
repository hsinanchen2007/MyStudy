### 解题思路
此处撰写解题思路
本题的关键是找到哨兵，会减少链表交换的复杂度，做题时最好自己画一下交换的顺序，那么这道题就迎刃而解了。
本题的head节点一直往后走，他的下一个节点即在哨兵后面，再讲链表链接，直至到链表尾
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
        $root = new ListNode(0);
        $root->next = $head;
        while ($head->next) {
            //这里有两个要交换的节点，声明两个tmp变量保存
            $tmp = $root->next;
            $tmp2 = $head->next->next;
            $root->next = $head->next;
            $root->next->next = $tmp;
            $head->next = $tmp2;
        }
        return $root->next;
    }
}
```