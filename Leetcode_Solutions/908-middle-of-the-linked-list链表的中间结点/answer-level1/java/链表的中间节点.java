### 解题思路
####可使用快慢指针法

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
    public ListNode middleNode(ListNode head) {
        //方法1：单指针法
        // int n=0;
        // ListNode p=head;
        // while(p!=null){
        //     n++;
        //     p=p.next;
        // }
        // int i=0;
        // p=head;
        // while(i<n){
        //     if(i==n/2){
        //         return p;
        //     }
        //     i++;
        //     p=p.next;
        // }
        // return null;
        //方法2：快慢指针法
        // ListNode low=head;
        // ListNode fast=head;
        // while(fast!=null&&fast.next!=null){
        //     low=low.next;
        //     fast=fast.next.next;
        // }
        // return low;
        //方法3：数组法:使用节点数组存储l各个链表节点
        ListNode[] A=new ListNode[100];
        int t=0;
        while(head!=null){
            A[t++]=head;
            head=head.next;
        }
        return A[t/2];

    }
}
```