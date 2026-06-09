### 解题思路
设置一个默认的节点
双指针，快指针先走n+1步
当快指针走到链表尾部时，慢指针走到要删除节点的前一个节点
删除该节点

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
     * @param Integer $n
     * @return ListNode
     */
    function removeNthFromEnd($head, $n) {
        if($head==null) return $head;
        //设置一个默认的节点
        $dumbNode = new ListNode(0);
        $dumbNode->next = $head;
        $fast = $slow = $dumbNode;
        //让fast比slow先走n+1步
        while($n+1){
            $fast = $fast->next;
            $n--;
        }     
        //fast走到尾部的时候slow就是要删除节点的前一个节点
        while($fast!==null){
            $slow = $slow->next;
            $fast = $fast->next;
        }
        //将slow的next指针指到next->next，即可删除slow的next
        $slow->next = $slow->next->next;
        
        return $dumbNode->next;
        
    }
}

```