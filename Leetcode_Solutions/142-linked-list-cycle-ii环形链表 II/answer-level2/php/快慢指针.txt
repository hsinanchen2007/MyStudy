### 解题思路
快慢指针

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
    // 快慢指针
    function detectCycle($head) {
        // 1. 若有环，找到快慢指针相遇的点
        $slow = $head;
        $fast = $head;
        $ptr1 = $head;
        while($fast !== null && $fast->next !== null) {
            $slow = $slow->next;
            $fast = $fast->next->next;
            if($slow === $fast) {
                // 2. 记录相遇的点
                $ptr2 = $fast;
                while($ptr1 !== $ptr2) {
                    $ptr1 = $ptr1->next;
                    $ptr2 = $ptr2->next;
                }
                // return $ptr1 与 return $ptr2 此时都是一样的
                return $ptr1;
                // return $ptr2;
            }
        }
        return null;
    }

    // 借助hashtable
    // function detectCycle($head) {
    //     $hashMap = [];
    //     $curr = $head;
    //     while($curr) {
    //         $key = array_search($curr, $hashMap);
    //         if($key !== false) return $curr;
    //         $hashMap[] = $curr;
    //         $curr = $curr->next;
    //     }
    //     return false;
    // }
}
```