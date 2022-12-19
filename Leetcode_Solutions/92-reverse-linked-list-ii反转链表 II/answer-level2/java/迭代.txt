```

    /**
    * Definition for singly-linked list.
    * public class ListNode {
    *     int val;
    *     ListNode next;
    *     ListNode(int x) { val = x; }
    * }
    */
    class Solution {
        public ListNode reverseBetween(ListNode head, int m, int n) {
            
            // 记录 m 之前的一个节点， 
            ListNode mPreNode = head;
            // 记录 m 节点，
            ListNode mNode = null;

            ListNode now = head;


            for(int i=1; i<m-1; i++){
                now = now.next;
            }

            // 当m = 1时，mNode 和 mPreNode 为同一个节点
            mPreNode = now;
            mNode = (m<=1)?mPreNode:now.next;
            
            // 翻转 m 到 n 的链表
            now = mNode;
            ListNode next = now.next;
            for(int i=m; i<n; i++){
                ListNode tmp = next.next;
                next.next = now;
                now = next;
                next = tmp;
            }
            
            // 当m=1时
            if(m==1){
                mNode.next = null;
                // ------------
                head = now;
            }else{
                mPreNode.next = now;
            }

            if(next != null){
                mNode.next = next;
            }else{
                mNode.next = null;
            }
            return head;
        }

    }
```
