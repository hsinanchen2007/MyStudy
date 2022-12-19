### 解题思路
1. 定位位置，移除节点
2. 若删除的位置为第一个，则直接把指针指向原始节点的下一个即可

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
     * @param Integer $val
     * @return ListNode
     */
    function deleteNode($head, $val) {
        $raw = $head;
        $pre = null;
        
        while ($head != null) {

            if($head->val == $val) {
                
                if($pre != null) {
                    // 记录了上一个节点位置 -> 删除的不是第一个
                    $pre->next = $head->next;
                } else {
                    // 记录了上一个节点位置 -> 删除是第一个
                    $raw = $head->next;
                }
                
                break;
            }

            $pre = $head;
            $head = $head->next;
        }

        return $raw;
    }
}
```