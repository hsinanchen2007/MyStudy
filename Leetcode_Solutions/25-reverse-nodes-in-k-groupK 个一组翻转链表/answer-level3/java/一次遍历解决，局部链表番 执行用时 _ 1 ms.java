### 解题思路
使用子链表来翻转，循环依次递增，当序号与K求余为1时记住子链表的开始节点，当序号能被K整除时就把当前节点当作子链表的尾节点，然后调用子链的翻转函数，翻转完之后要做的事：
1. 翻转后的尾节点指向下个节点，因为翻转子链后尾节点会为空
2. 把上次翻转的尾节点指向目前反转子链表的头节点
3. 保存当前翻转子链表的尾节点

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || head.next == null || k == 1) return head;

        ListNode prev = null;
        ListNode left = null;
        ListNode right = null;
        ListNode cur = head;
        ListNode newHead = head;
        int n = 1;
        while(cur != null) {
            if( n % k == 1) {
                left = cur;
                cur = cur.next;
            }else if( n % k == 0){
                right = cur;
                cur = cur.next;

                //上次翻转的子链表尾节点当这个子链表的头元素，进行翻转
                reverseSubList(prev, left, right);
                
                //翻转后的尾节点指向下个节点
                left.next = cur;
                
                //把上次翻转的尾节点指向目前翻转子链表的头节点
                if(prev != null){
                    prev.next = right;
                }
                //保存当前翻转子链表的尾节点
                prev = left;

                if(n / k == 1) {
                    newHead = right; 
                }
            }else{
                cur = cur.next;
            }
            ++n;
        }

      return newHead;

    }


    /**
     * 翻转链表
     * @param newHead 上次翻转的子链表尾节点当这个子链表的头元素
     * @param from 开始节点
     * @param end 结束节点
     */
    void reverseSubList(ListNode newHead,ListNode from, ListNode end) {
        
        ListNode cur = from;
        while( cur != null ) {
            ListNode second = cur.next;
            cur.next = newHead;
           
            newHead = cur;
            cur = second;
            
            //反转到最后节点就结束
            if(newHead == end){
                break;
            }
        }
    }
}
```