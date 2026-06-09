### 解题思路
此处撰写解题思路
分2步实现：
(1)合并k个列表
(2)归并排序
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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length==0){
            return null;
        }
        ListNode[] mynode=new ListNode[2];
        mynode[0]=lists[lists.length-1];
        mynode=mergeNode(lists,lists.length,mynode);
        //return mynode[0];
        return initialMerge(mynode[0]);//mynode[0];

    }
/*
*合并k个列表
*/
    public ListNode[] mergeNode(ListNode[] lists,int len,ListNode[] headAndLast){
        //ListNode[] mynode=new ListNode[2]();
        System.out.println("length="+len);
        ListNode last;
        if (headAndLast[1]!=null){
            headAndLast[1].next=lists[len-1];
        }
        last=lists[len-1];
        while(last!=null){
                if (last.next==null){
                    headAndLast[1]=last;
                    break;
                }else{
                    last=last.next;
                }
        } 
        if(headAndLast[0]==null){
            headAndLast[0]=lists[len-1];
        }
        if (headAndLast[1]==null){
            headAndLast[1]=last;
        }
 
        if (len-1==0){
            return headAndLast;
        }else{

            return mergeNode(lists,len-1,headAndLast);
        }

    }

    public ListNode mergeSel(ListNode l1,ListNode l2){
        ListNode tmp,mynew;
        ListNode firstNode;
        
        if (l1==null){
            return l2;
        }
        if(l1!=null && l2!=null){
            if (l1.val>l2.val){
                tmp=l1;
                l1=l2;
                l2=tmp;
            }
        }
        firstNode=l1;
        while(l2!=null){
            while(l1!=null){
                if (l2.val>=l1.val){
                    if (l1.next==null){ 
                        mynew=new ListNode(l2.val);
                        l1.next=mynew;
                        break;
                   }else if(l2.val<=l1.next.val){ 
                        tmp=l1.next;
                        mynew=new ListNode(l2.val);
                        l1.next=mynew;
                        mynew.next=tmp;
                        l1=mynew;
                        break;
                   }else{
                       l1=l1.next;
                   }
                    
                }else{
                    l1=l1.next;
                }
            }
            l2=l2.next;
        }
        return firstNode;
        

    }

/**
***归并排序
**//
    public ListNode initialMerge(ListNode head){
        ListNode nextNode,next2Node;
        ListNode midNode;
        if(head==null || head.next==null){
           return head;
        }
        nextNode=head;
        next2Node=head;
        while (next2Node.next!=null && next2Node.next.next!=null){
            nextNode=nextNode.next;
            next2Node=next2Node.next.next;
        }

        //nextNode=nextNode.next;
        midNode=nextNode.next;
        nextNode.next=null;

        return mergeSel(initialMerge(head),initialMerge(midNode));

    }
}
```