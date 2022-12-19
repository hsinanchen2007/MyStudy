主要是参考之间的解法：这个题是来源于剑指offer里面的题，是面试百度的时候，真是遇到的，自己之前也遇到过，但是每次的学习的不好。

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
        if (empty($head) || empty($head->next)) {
            return $head;
        }

        $pre = $this->reverseList($head->next);
        $head->next->next = $head;
        $head->next = null;
        return $pre;
    }
}
```
