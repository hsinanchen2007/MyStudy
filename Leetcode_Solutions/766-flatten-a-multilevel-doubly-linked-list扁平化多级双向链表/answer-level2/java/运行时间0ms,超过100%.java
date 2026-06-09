  1. 递归函数flatten1 返回子节点不为空的后续以排好序的最后一个不为空的节点tail
  2. 把tail拼接在node 和node.next之间



public Node flatten(Node head) {
        Node node = head;
        if (node == null)
            return null;
        flatten1(node);
        return head;
    }

    public Node flatten1(Node head) {
        if (head == null)
            return null;
        Node node = head;
        Node tail = node;
        while (node != null) {

           if (node.child!=null){
                Node temp = node.child;

                Node con = node.next;
                Node cur = flatten1(node.child);
<!-- node和 temp = node.child重新拼接-->
                node.next = temp;
                temp.prev = node;
                node.child = null;

<!-- node.next不为空，拼接到cur(tail)的next -->
                if (con != null) {
                    con.prev = cur;
                    cur.next = con;
                }
                tail = node;
                node = con;
            }else {
               tail = node;
               node = node.next;
           }
        }
        return tail;
    }