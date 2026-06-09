## 方法1
双重循环，先遍历获取链表的长度。然后第二重循环找到要删的结点为第`链表长度-n+1`个结点，然后删除。
## 方法二：双指针
在解题的时候报错了，开始有一种情况没有考虑到，当删除链表的正数第一个结点的时候要做特殊的处理。java实现：
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur=head;
        // cur.next=head;
        ListNode nextNode=head;
        for(int i=0;i<n;i++){
            nextNode=nextNode.next;
        }
        if(nextNode==null) {head=head.next;return head;}
        while(nextNode.next!=null){
            cur=cur.next;
            nextNode=nextNode.next;
        }
        cur.next=cur.next.next;

        return head;

    }
}
```
## 方法三：双指针加哑结点
构造一个哑结点pre，两个指针。返回的始终是`pre.next`。当要删除正数第一个结点的时候，指针first开始指向哑结点pre，然后删掉第一个结点后`pre.next就是此时链表的第一个结点`。很妙。
js代码实现
```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
var pre=new ListNode(0);
pre.next=head;
var second=pre;var first=pre;
for(var i=0;i<n;i++){
    second=second.next;
}
while(second.next!=null){
    first=first.next;
    second=second.next;
}
first.next=first.next.next;
return pre.next;

};
```
