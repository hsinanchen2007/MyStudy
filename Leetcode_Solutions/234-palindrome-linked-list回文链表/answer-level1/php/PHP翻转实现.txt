### 解题思路
先把原来的值放到一个数组中，然后翻转这个数组，如果翻转过来的数组和原来的一样就是回文。

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
     * @return Boolean
     */
    function isPalindrome($head) {
        $vals = [];
        while($head){
            $vals[] = $head->val;
            $head = $head->next;
        }
        return $vals == array_reverse($vals);
    }
}
```