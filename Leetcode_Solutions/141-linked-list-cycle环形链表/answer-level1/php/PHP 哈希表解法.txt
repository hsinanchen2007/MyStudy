### 解题思路
用了哈希表。把已经走过的节点放到表中，如果重复了肯定就是有环

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
    function hasCycle($head) {
        $hashMap = [];
        while($head){
            if(in_array($head,$hashMap)){
                return true;
            }
            $hashMap[] = $head;
            $head = $head->next;
        }
        return false;
    }
}
```