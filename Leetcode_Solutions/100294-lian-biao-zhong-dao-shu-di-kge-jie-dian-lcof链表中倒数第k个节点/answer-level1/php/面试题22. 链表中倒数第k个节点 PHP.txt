### 解题思路
之前腾讯面试遇到过，纪念一下

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
    function getKthFromEnd($head, $k) {
        $a = $head;
        $b = $head;
        
        // 记录跳到了第几个
        $i = 0;

        while($a != null) {
            // 从第 k 个开始，跟着一起跳
            if($i++>=$k) {
                $b = $b->next;
            }
            $a = $a->next;
        }

        return $b;

    }
}
```