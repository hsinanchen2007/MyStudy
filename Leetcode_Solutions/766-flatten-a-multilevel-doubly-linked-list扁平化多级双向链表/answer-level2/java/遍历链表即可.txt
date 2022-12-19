遍历主链，遇到有子节点的，处理子节点后，把子节点链插入到主链中继续遍历。
子节点处理：
   1.设置子节点的pre
   2.遍历子节点，找出链尾，子节点处理不需要处理子节点的子节点
   3.把链尾的next链接到主链中
   4.如果主链的链接进来的节点存在，则设置节点的pre为子节点的尾链
class Solution {
    public Node flatten(Node head) {
            Node cur = head;
            if (cur == null) {
                return null;
            }
            while (cur != null) {
                if (cur.child != null) {
                    cur.next = processChild(cur);
                    cur.child = null;
                }
                cur = cur.next;
            }
            return head;
        }

        private Node processChild(Node cur) {
            Node child = cur.child;
            child.prev = cur;
            while (child.next != null) {
                child = child.next;
            }
            child.next = cur.next;
            if (cur.next != null) {
                cur.next.prev = child;
            }
            return cur.child;
        }
}