### 解题思路
从第1个开始做翻转，第k个翻完时，如果还有k+1项，就把第1项的next指向递归调用从k+1项开始的下一组k个元素，每次递归都是返回本次递归的第k项。
递归2种结束情况：1.head为null直接返回null 2.本组不够k项就把已经反转的项重新反转回来返回本组第一项
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
     * @param Integer $k
     * @return ListNode
     */
    function reverseKGroup($head, $k) {
        if ($head == null) {
            return $head;
        }
        $cnt = $k;
        $pre = null;
        $cur = $head;
        while ($cur && $cnt-- > 0) {
            $next      = $cur->next;
            $cur->next = $pre;
            $pre       = $cur;
            $cur       = $next;
        }
        if ($cnt > 0) {
            $next =  $this->reverseKGroup($pre, $k - $cnt);
            return $next;
        }else{
            $next = $this->reverseKGroup($cur,$k);
        }
        $head->next = $next;

        return $pre;
    }
}
```