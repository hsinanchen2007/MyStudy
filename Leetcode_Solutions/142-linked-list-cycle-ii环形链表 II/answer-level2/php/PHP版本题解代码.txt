 //解题思路：
 //第一步、参照环行链表一的解法先:https://leetcode-cn.com/problems/linked-list-cycle/ 先把这个做出来
 //第二步、A指针从头开始走，B指针从相遇处开始走，再次相遇则为环形入口处

```
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
    function detectCycle($head) {
        
         //此处为第一步 快慢同时走，然后找出相遇点
        $fast = $head;
        $slow = $head;

        //找相遇点
        while(true){

            //走到头了 或者 单个链表
            if($fast == null && $fast->next == null) return null;

            $fast = $fast->next->next;
            $slow = $slow->next;

            if($fast === $slow) break; //找到相遇点 相遇点为slow
        }

        $fast = $head;//fast从头开始走

        //直到相遇
        while($fast != $slow){
            $slow = $slow->next;
            $fast = $fast->next;
        }

        return $fast;
    }
}
```
