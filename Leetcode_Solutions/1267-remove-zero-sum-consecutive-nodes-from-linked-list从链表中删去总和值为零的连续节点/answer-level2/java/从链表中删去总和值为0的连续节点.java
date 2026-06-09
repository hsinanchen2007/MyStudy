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
    public ListNode removeZeroSumSublists(ListNode head) {
        //利用哈希表的性质两次遍历
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        Map<Integer,ListNode> map=new HashMap<>();
        //第一次遍历，建立节点和与单链表的哈希映射,如果同一个和多次出现，则会覆盖，即记录该sum最后一次出现的节点
        int sum=0;
        //从下面的语句可以看出来，具有虚拟头结点还可以便于删除链表的首节点
        for(ListNode d=dummy;d!=null;d=d.next){
            sum+=d.val;
            map.put(sum,d);
        }
        //第二次遍历，若当前节点的sum在后面出现，则表示两节点之间所有节点的元素和为0，可以直接删除掉。
        sum=0;
        for(ListNode d=dummy;d!=null;d=d.next){
            sum+=d.val;
            if(map.containsKey(sum))
            {
                d.next=map.get(sum).next;
            }
        }

        return dummy.next;
    }
}
```