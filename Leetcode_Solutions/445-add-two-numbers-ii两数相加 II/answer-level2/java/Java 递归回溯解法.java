### 解题思路
1. 因为Java 没有引用指针的缘故，所以递归的时候只能将前一个结点传出 在外层进行操作
2. 递归要双栈方法慢很多，因为涉及到很多函数的入栈出栈操作，在汇编层会增加很多函数栈操作的指令，这些是非常耗时的，所以时间复杂度比较高，也非常占用系统内存。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int len1=len(l1);
        int len2=len(l2);
         if(len1<len2){
            while(len1!=len2){
                ListNode newHeader=new ListNode(0);
                newHeader.next=l1;
                l1=newHeader;
                len1++;
            }
         }
         else if(len2<len1){
            while(len2!=len1){
                ListNode newHeader=new ListNode(0);
                newHeader.next=l2;
                l2=newHeader;
                len2++;
            }
         }
         ListNode header=add(l1,l2);
         if(header.val>=10){
             ListNode newHeader=new ListNode(0);
             newHeader.val=header.val/10;
             header.val=header.val%10;
             newHeader.next=header;
             header=newHeader;
         }
         return header;


        
    }
    private int len(ListNode l){
     int len=0;
     while(l!=null){
         l=l.next;
         len++;
     }
     return len;
    }
    private ListNode add(ListNode l1,ListNode l2){
         int x=0,y=0;
         System.out.println(l1);
         System.out.println(l2);
         if(null==l1.next&&null==l2.next){
             ListNode tail=new ListNode(0);
             tail.val=l1.val+l2.val;
             return tail;
         }
         ListNode returnNode=add(l1.next,l2.next);
         if(l1!=null)x=l1.val;
         if(l2!=null)y=l2.val;
         ListNode header=new ListNode(0);
         header.val=x+y+returnNode.val/10;
         returnNode.val=returnNode.val%10;
         header.next=returnNode;
         return header;
    }
}
```