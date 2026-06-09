1. 设置两个变量，一个count用于存储节点总数，一个middle用于存储节点向前回溯时经过的节点数
2. 判断count与middle之间的关系，当middle指代的节点为中间节点时，直接将该节点返回
```
class Solution {
    private int count;
    private int middle;
    
    public ListNode middleNode(ListNode head) {
        count = 0;
        middle = 0;
        return cacu(head);
    }

    public ListNode cacu(ListNode head) {
        if (head == null) return null;
        count++;
        ListNode node = cacu(head.next);
        if (node == null) {
            middle++;
            if (middle == (count % 2 == 1 ? count/2+1 : count/2)) {
                return head;
            }
        }
        return node;
    }
}
```
