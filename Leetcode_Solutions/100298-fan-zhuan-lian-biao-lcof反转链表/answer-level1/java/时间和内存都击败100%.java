### 解题思路
1.定义一个反转的头结点reverseList，和用来遍历的ListNode指针temp。2.计算出原有节点的数目。3.reverseList=最后一个节点。4.通过循环把前几个节点都加入到reverseList后面。5.一定要 temp.next = head; head.next=null;一个用来添加最后一个节点（也就是原来的第一个），后一句是为了把原有的第一个节点的next指针设为0，不然又会和原来的连起来。

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
        if(head==null)
            return head;
        ListNode reverseList = null;
        ListNode temp = head;
        int count = 1;
        while(temp.next!=null){
            count++;
            temp = temp.next;
        }
        reverseList = temp;
        count--;
        while(count>0){
            int t = count;
            ListNode temp2 = head;
            while((--t)>0){
                temp2 = temp2.next;
            }
            temp.next=temp2;
            temp=temp2;
            count--;
        }
        temp.next = head;
        head.next=null;
        return reverseList;

    }
}
```