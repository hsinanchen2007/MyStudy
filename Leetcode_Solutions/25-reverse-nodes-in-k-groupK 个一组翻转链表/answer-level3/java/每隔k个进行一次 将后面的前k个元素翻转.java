### 解题思路
首先今天看了另一道题【翻转链表中第m到第n个元素】的题解，我觉得写得特别好，其中有只翻转前n个：https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/

指针p初使在头结点，p=p.next k次，进行一次将p.next的前k个元素翻转的操作
（先判断一下剩余节点格式是否够k个，不够的话return）

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
      
        ListNode temp=new ListNode(0);
        temp.next=head;
        ListNode p=temp;
        while(p!=null){
        
            if(ok(p,k)==true)p.next=reverseFirst(p.next,k);
            else return temp.next;

            int n=k;
            while(n-->0){
                    p=p.next; 
                    if(p==null)return temp.next;
            }
       
        }
        return temp.next;
    }
//判断一下剩余节点格式是否够k个
    public boolean ok(ListNode p,int k){
        ListNode t=p;
        while(k-->0){
            p=p.next;
            if(p==null)return false;
        }
        return true;
    }
    public ListNode su;
//翻转链表前k个元素
    public ListNode reverseFirst(ListNode head,int k){
      
        if(k<2){
            su=head.next;
            return head;
        }
        ListNode p=reverseFirst(head.next,k-1);
        head.next.next=head;
        head.next=su;
        return p;
    }
}
```