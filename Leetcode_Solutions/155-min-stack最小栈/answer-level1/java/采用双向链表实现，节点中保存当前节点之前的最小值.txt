```
class MinStack {

    //自定义双链表，保存当前节点值+当前节点以前的最小值（含当前节点）
    class Node {
        int val;
        Node next;
        Node pre;
        //当前节点前（含当前）的最小值
        int curMin;

        Node(int val) {
            this.val = val;
        }
    }

    private Node head = new Node(0);
    private Node cur;

    /**
     * initialize your data structure here.
     */
    public MinStack() {

    }

    public void push(int x) {
        if (cur == null) {
            cur = new Node(x);
            head.next = cur;
            cur.pre = head;
            cur.curMin = x;
        } else {
            cur.next = new Node(x);
            cur.next.pre = cur;
            cur = cur.next;
            cur.curMin = Math.min(cur.pre.curMin, x);
        }
    }

    public void pop() {
        cur.pre.next = null;
        cur = cur.pre;
        if (cur == head)
            cur = null;
    }

    public int top() {
        return cur.val;
    }

    public int getMin() {
        return cur.curMin;
    }
}
```