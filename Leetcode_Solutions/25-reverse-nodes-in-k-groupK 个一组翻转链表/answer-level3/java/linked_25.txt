### 解题思路
此处撰写解题思路
![866b404c6b0b52fa02385e301ee907fc015742c3766c80c02e24ef3a8613e5ad-k个一组翻转链表.png](https://pic.leetcode-cn.com/86e7645639b1d0869d96f9408f55f380008f75c23386c178b1bfe3cd2af55e78-866b404c6b0b52fa02385e301ee907fc015742c3766c80c02e24ef3a8613e5ad-k%E4%B8%AA%E4%B8%80%E7%BB%84%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.png)

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
        int count =0;
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode pre=dummy ;
        ListNode end=dummy;
        ListNode start=dummy ;
        ListNode next;
        while (end.next!=null&&k!=1){
            end=end.next;
            count++;
            if (count%k==1){
                start=end;

            }
            if (count%k==0){
                next=end.next;
                adver(start,k);
                pre.next=end;
                start.next=next;
                pre=start;
                end=start;
            }
        }
        return dummy.next;
    }

    public  void adver (ListNode start,int k){
        ListNode newHead =null;
        ListNode node =start;
        ListNode next;
        while (k>0){
            next=node.next;
            node.next=newHead;
            newHead=node;
            node=next;
            k--;

        }
    }
}

```