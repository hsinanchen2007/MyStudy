### 解题思路
![image.png](https://pic.leetcode-cn.com/3e65ab5884e39a4ccd9ffd95f15c519620e485b59bd2f1837adbc45fa4e5b85d-image.png)


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
    public final ListNode reverseBetween(ListNode head, int m, int n) {
        if(head==null||m>=n){return head;}
        int target=1;
        //虚拟头结点
        ListNode tempHead=new ListNode(0);
        tempHead.next=head;
        //断开前缀
        ListNode beforeTarget=null;
        ListNode end=null;
        ListNode start=null;
        //断开后缀
        ListNode endNextTarget=null;
        while(head!=null){
            if(target==m-1){beforeTarget=head;}
            if(target==m){start=head;}
            if(target==n){end=head;}
            if(target==n+1){endNextTarget=head;}
            head=head.next;
            target++;
        }
        if(m>target||n>target){return head;}
        //m>=n、m或n越界情况已处理，mn必在链表内。头部加虚节点，n为结尾的情况不影响
        end.next=null;
        ListNode newStart=reverse(null,start);
        //m为开头的情况已处理
        if(beforeTarget==null){beforeTarget=tempHead;}
        beforeTarget.next=newStart;
        start.next=endNextTarget;
        return tempHead.next;
    }

    // public final ListNode reverse2(ListNode head){
    //     if(head==null){return null;}
    //     Stack<ListNode> stack=new Stack<ListNode>();
    //     while(head!=null){
    //         stack.push(head);
    //         head=head.next;
    //     }
    //     ListNode temp=stack.pop();
    //     ListNode newHead=temp;
    //     while(stack.size()!=0){
    //         temp.next=stack.pop();
    //         temp=temp.next;
    //     }
    //     return newHead;
    // }

    public final ListNode reverse(ListNode before,ListNode head){
        if(head.next==null){
            head.next=before;
            return head;
        }
        ListNode result=reverse(head,head.next);
        head.next=before;
        return result;
    }
}
```