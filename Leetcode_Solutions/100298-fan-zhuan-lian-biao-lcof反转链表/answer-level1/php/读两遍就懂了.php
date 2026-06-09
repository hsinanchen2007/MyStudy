### 解题思路
四句话，首先第一第二句就是为了推进head
中间两句，对着用例，读两遍就懂了

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

        while($head) {
           $next = $head->next; //用于推进head

           $head->next = $pre; //当前的下一个 连接上 前一个
           $pre = $head;  //前一个 变成 当前

           $head = $next; //推进head
        }

        return $pre;
    }
}
```