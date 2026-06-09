思路是给每一个曾经遍历过的节点做标记，但是由于节点类是系统定义好了的，无法再添加新的成员变量，所以我们用next做为标记，把每一个遍历过了的节点的next置为head，这样一旦遍历到一个next为head的节点就说明循环了。
```
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        while(head.next!=null){
            if(head.next == head){
                return true;
            }
            else{
                ListNode tmp = head.next;
                head.next = head;
                head = tmp;
            }
        }
        return false;
    }
}
```
