### 解题思路
此处撰写解题思路

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

    //迭代
    public ListNode swapPairs(ListNode head){
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode temp=dummy;
        while(temp!=null&&temp.next!=null){
            ListNode first=temp.next;
            ListNode second=temp.next.next;
            //如果second==null说明已经到达链表尾部了尾部是只有一个元素
            if(second==null){
                //直接将尾部节点添加到链表尾部
                temp.next=first;
                temp=first;
            }else{
                //如果second!=null说明满足交换条件,直接进行交换
                first.next=second.next;
                second.next=first;
                temp.next=second;
                temp=first;
            }
        }
        return dummy.next;
    }
    //递归
    public ListNode swapPairs(ListNode head){
        if(head==null||head.next==null){
            return head;
        }
        ListNode first=head;
        ListNode second=head.next;
        first.next=swapPairs(second.next);
        second.next=first;
        return second;
    }

```