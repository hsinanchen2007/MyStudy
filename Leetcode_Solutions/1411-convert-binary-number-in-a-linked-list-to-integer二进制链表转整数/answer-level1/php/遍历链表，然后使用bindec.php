### 解题思路

遍历 + bindec
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
     * @return Integer
     */
    function getDecimalValue($head) {
        $str = '';
        while($head!=null){
            $str .= $head->val;
            $head = $head->next;
        }

        return bindec($str);
    }
}
```