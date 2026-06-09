### 解题思路
此处撰写解题思路
看注释即可

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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null||head.next==null||k==0)return head;//特殊的几种情况
        List<ListNode> nodes=new ArrayList();
        int length=0;
        ListNode cur=head;
        while(cur!=null){//计算链表长度
            length++;
            nodes.add(cur);
            cur=cur.next;
        }
        if(k%length==0)return head;//说明移动完还是原链表
        nodes.get(nodes.size()-1).next=head;//首尾相连
        ListNode res=nodes.get(length-(k%length));
        nodes.get(length-(k%length)-1).next=null;//断开连接
        return res;
        
    }
}
```