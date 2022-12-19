### 解题思路
此处撰写解题思路
快慢指针方法，一个指针走一步，另一个指针走两步，当第二个指针走到尾的时候，第一个就是二分之一的位置
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
        //快慢指针方法
        $firstNode = $secondNode = $head;
        while ($secondNode && $secondNode->next) {
            
            $firstNode = $firstNode->next;
            $secondNode = $secondNode->next->next;
            
        }
        return $firstNode;
    }
}
```