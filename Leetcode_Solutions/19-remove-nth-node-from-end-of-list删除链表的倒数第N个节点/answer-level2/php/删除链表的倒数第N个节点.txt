### 解题思路
使用快慢指针进行处理, 遍历链表, 快指针从头遍历, 当快指针遍历距离慢指针n+1(为了获取慢指针前一个节点)位时, 慢指针开始前进, 当快指针到结尾时, 此时慢指针就在链表倒数第N个节点的父节点上.
将父节点指针指向子子节点, 并释放中间节点完成链表节点删除操作.

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
     * @param Integer $n
     * @return ListNode
     */
    public function removeNthFromEnd($head, $n) {
        if (!$head || !$n) {
            return $head;
        }

        $cur = $head;
        $slow = null; // 慢指针的前项节点
        $i = 0;
        while ($cur) {
            // 获取父节点
            if ($i == $n + 1) {
                $slow = $head;
            }
            $slow && $slow = $slow->next;
            $cur = $cur->next;
            $i++;
        }

        if ($n == $i -1) {
            $slow = $head;
        }
        if ($n >= $i) {
            $head = $head->next;
        }

        if ($slow) {
            $deletNode = $slow->next;
            $slow->next = $slow->next->next;
            unset($deletNode);
        }
        return $head;
    }

}
```