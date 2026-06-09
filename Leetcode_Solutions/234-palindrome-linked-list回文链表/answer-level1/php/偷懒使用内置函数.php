### 解题思路
偷懒写法，但执行还挺快。。。

执行用时 :16 ms, 在所有 PHP 提交中击败了100.00% 的用户
内存消耗 :25.7 MB, 在所有 PHP 提交中击败了7.69%的用户

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
        //偷懒法：遍历链表后，使用array_reverse翻转
        $listArr = [];
        while($head !== null) {
            $listArr[] = $head->val;
            $head = $head->next;
        }

        return $listArr == array_reverse($listArr) ? true : false;
    }
}
```