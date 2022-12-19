### 解题思路
求出链表长度，取出中间点，根据链表长是技术还是偶数判断一下即可

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
    function middleNode($head) {
        //求链表长度
        $len = 0;
        $p = $head;
        while($p)
        {
            $len++;
            $p = $p->next;
        }
        $mid = ceil($len / 2);
        if($len%2 == 0)
            $mid++;
        $ans = $head;
        $i = 1;
        while($i<$mid)
        {
            $ans = $ans->next;
            $i++;
        }
        return $ans;
    }
}
```