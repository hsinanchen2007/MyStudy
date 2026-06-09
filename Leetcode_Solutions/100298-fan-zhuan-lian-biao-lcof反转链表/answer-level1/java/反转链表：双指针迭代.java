### 解题思路
用两个指针，分别初始化为 null 和 head(原链表的头节点)，再利用一个 ”中间值“ tmp节点，依次迭代替换两个指针在链表中的位置，相当于”一个结点跑，一个节点追“，最后一个指针跑出链表（变成null），一个指针跑到原链表的最后一个节点，也就是我们得到的最后链表的头节点。
其实思路大致如上，写代码可能稍微有些绕，建议画图比较稳妥;
（1）初始化指针：now_head=head; new_head=null; tmp=null;
（2）进入循环，迭代替换 now_head 和 new_head，第一步利用tmp记录下now_head的下一个节点，也就是此次循环now_head的迭代节点； 第二步将 now_head 节点指向 new_head（相当于调整链表的方向）；第三步就是把 new_head 和 now_head 分别向前移动一个节点;
（3）最后循环结束，此时now_head=null,new_head=原链表的最后一个非空节点，就是此时新链表的头节点

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
    public ListNode reverseList(ListNode head) {
        ListNode new_head=null;
        ListNode now_head=head;
        ListNode tmp=null;
        while(now_head!=null){
            //记录当前节点的下一个节点
            tmp=now_head.next;
            //将当前节点指向new_head
            now_head.next=new_head;
            //将 new_head 和 now_head 向后面节点移动，直到now_head为null，此时new_head就成了原链表的最后一个节点
            new_head=now_head;
            now_head=tmp;
        }
        return new_head;
    }
}
```