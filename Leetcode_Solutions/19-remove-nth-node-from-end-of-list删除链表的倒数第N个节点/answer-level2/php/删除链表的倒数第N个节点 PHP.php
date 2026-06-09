### 解题思路
设置一个默认的节点
双

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

function removeNthFromEnd($head, $n) {
        $dumb = new ListNode(0);
        $dumb->next = $head;
        $length = 0;
        $first = $head;
        while($first!==null){
            $length++;
            $first = $first->next;
        }

        $first = $dumb;
        $length -= $n;
        while($length){
            $length--;
            $first = $first->next;
        }
     
        $first->next = $first->next->next;
        return $dumb->next;
    }

```

### 解题思路
设置默认头结点
先遍历获取链表长度
然后根据n和length的差
指针指到要删除节点前节点，并删除

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
        $dumb = new ListNode(0);
        $dumb->next = $head;
        $length = 0;
        $first = $head;
        while($first!==null){
            $length++;
            $first = $first->next;
        }

        $first = $dumb;
        $length -= $n;
        while($length){
            $length--;
            $first = $first->next;
        }
     
        $first->next = $first->next->next;
        return $dumb->next;
    }
}


```