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
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        //如果k=1不用反转直接返回结果
        if(k==1){
            return head;
        }
        //用于记录链表的深度,当达到k的时候进行翻转
        int i=0;
        //记录翻转链表的头节点比如需要翻转1->2->3,那么将节点1进行存储
        ListNode h=head;
        //用于存放需要翻转的链表,需要翻转的链表是temp.next
        ListNode temp=new ListNode(0);
        //存放需要翻转链表的尾结点
        ListNode curr=temp;
        //最终结果
        ListNode result=new ListNode(0);
        //记录翻转之后的结果
        ListNode currResult=result;
        //存在head==null但是i==k的情况,如果只判断head==null,会漏掉最后一次
        //比如1->2 k=2,当i==k时候head变成空了,但是需要继续处理所以循环条件加入i==k
        while(head!=null||i==k){
            //i==k说明达到一组进行翻转
            if(i==k){
                //翻转链表
                ListNode reverse=reverse(temp.next);
                //计入结果
                currResult.next=reverse;
                //将头结点重新赋值到currResult中,因为翻转之后头结点就是翻转之后链表的尾结点,下一组头结点将是上一组的尾结点,所以替换currResult
                currResult=h;
                //重新计入头结点
                h=head;
                //初始化变量
                //重新赋值temp,用于重新存放翻转链表
                temp=new ListNode(0);
                //重新赋值
                curr=temp;
                //重新赋值
                i=0;
            }else{
                //使得temp计入要翻转的链表,curr为当前要翻转的尾结点
                ListNode next=head.next;
                head.next=null;
                curr.next=head;
                curr=curr.next;
                head=next;
                i++;
            } 
        }
        //最终剩余不满足k组的节点重新赋值到链上
        currResult.next=temp.next;
        return result.next;
        
    }
    //使用递归翻转链表
    private ListNode reverse(ListNode head){
        if(head==null||head.next==null){
            return head;
        }
        ListNode listNode=reverse(head.next);
        head.next.next=head;
        head.next=null;
        return listNode;
    }
}
```