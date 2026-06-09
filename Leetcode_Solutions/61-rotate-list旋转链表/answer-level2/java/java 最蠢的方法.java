### 解题思路
按照旋转数组的逻辑，将所有节点都取出保存在list，然后定义一个数组，保存旋转过后相应节点的位置，最后按照数组顺序输出。

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
        if(head == null) return null;
        List<ListNode> list = new ArrayList<>();
        while(head!=null){
            list.add(head);
            head = head.next;
        }  
        ListNode[] nodes = new ListNode[list.size()];
        //将节点按旋转过后的顺序保存进数组
        for(int i=0;i< list.size();i++){
            nodes[(i + k)%list.size()] = list.get(i); 
        }
        ListNode ans = new ListNode(-1);
        ListNode pre = nodes[0];
        ans.next = pre;
        //按对应的顺序重构链表
        for(int i=1;i< nodes.length;i++){
            pre.next = nodes[i];
            pre = pre.next;
        }
        //将最后一个节点的next置空
        pre.next = null;
        return ans.next;
    }
}
```