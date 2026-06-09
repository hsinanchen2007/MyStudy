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
    public boolean isPalindrome(ListNode head) {
        //判断为空
        if (head == null || head.next == null) return true;

        //快慢指针
         ListNode fast=head.next,slow=head;

         //快慢移动
        while(fast!=null&&fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
         //偶数节点判断

        if(fast!=null)
        slow=slow.next;


         //切表
         cut(head,slow);

        //反转后半段字符


         //判断是否相等
      return  isEqual(head,reverse(slow));


    }


    //切割函数
    public void cut(ListNode head,ListNode cutnode){
        //判断分割位置
        while(head.next!=cutnode){
            head=head.next;
        }
        head.next=null;
    }

    //反转函数
   private ListNode reverse(ListNode head){
       //新节点保存反转之后的数组
       ListNode newhead=null;
        while(head!=null){
            ListNode tempnode=head.next;
            head.next=newhead;
            newhead=head;
            head=tempnode;

        }



       return newhead;
   }

    //判断函数
public boolean isEqual(ListNode l1,ListNode l2){
        while(l1!=null&&l2!=null){
            if(l1.val!=l2.val) return false;
            l1=l1.next;
            l2=l2.next;
        }

        return true;

}



}
```