### 解题思路
采用步长模式，双指针思想

玩过王者荣耀的人应该知道，有个英雄叫元歌、傀儡距离真身之间有一个最大距离。当到达最大距离时，真身会随着傀儡移动。
傀儡出去探路，一旦发现危险（最后的节点），操作可以跳回到真身（应该操作的指针）。

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
     * 步长方法
     *
     * @param ListNode $head
     * @param Integer $n
     * @return ListNode
     */
    function removeNthFromEnd($head, $n) {
        $node = $head;
        $pre = $node;
        $i = 0;
        while ($node != null) {
            if ($i > $n) $pre = $pre->next;
            $node = $node->next;
            $i++;
        }

        if ($pre->next != null) {
            if ($i > $n) {
                $pre->next = $pre->next->next;
            } else {
                $head = $pre->next;
            }
        } else {
            $head = new ListNode(null);
        }

        return $head;
    }
}
```