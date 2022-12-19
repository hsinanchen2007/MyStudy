### 解题思路
使用快慢指针

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
    public int kthToLast(ListNode head, int k) {
        //链表的长度未知，所以无法正着求解
        
        /*
        List<ListNode> list=new ArrayList<>();
        ListNode node=head;
        while(node!=null){
            list.add(node);
            node=node.next;
        }
        int size=list.size();
        return list.get(size-k).val;
        */

        //不使用辅助空间 快慢指针
        int fast=0;
        ListNode fnode=head;
        ListNode lnode=head;
        while(fnode!=null&&fast<k){
            fnode=fnode.next;
            fast++;
        }
        while(fnode!=null){
            fnode=fnode.next;
            lnode=lnode.next;
        }
        return lnode.val;


    }
}
```