### 解题思路
此处撰写解题思路

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
        if($head==null) return null;
        if($head->next==null)return $head;
        $pNext=$head;
        $leftNode=null;
        $rightNode=$pNext->next;
        while($rightNode)
        {
            $pNext->next=$leftNode;
            $leftNode=$pNext;
            $pNext=$rightNode;
            $rightNode=$rightNode->next;
        }
        $pNext->next=$leftNode;
        return $pNext;
    }
}
```