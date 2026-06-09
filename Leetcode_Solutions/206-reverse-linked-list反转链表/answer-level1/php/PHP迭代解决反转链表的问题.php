### 解题思路

通过学习B站的视频学到的方法
参考 [一分钟教你链表反转](https://www.bilibili.com/video/av24376909)

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
        $pre = null;
        while ($head) {
            $tmp = $head;
            $head = $head->next;
            $tmp->next = $pre;
            $pre = $tmp;
        }
        return $pre;
    }
}
```