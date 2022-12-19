参考了前面几位大神的代码，但加入了 dummy node。

直接看代码，pre 表示当前需要寻找 next 的节点。在每一层最开始，把 pre 设为 dummy node。这样不用每一层都先寻找第一个点。

做完这一层连接后，直接把下一层的起始 parent 设为 dummy.next。dummy node 的加入简化了代码。

```
    public Node connect(Node root) {
        if (root == null)
            return null;
        
        Node parent = root;         // 在上层移动
        Node dummy = new Node(0);   // dummy.next指向下层第一个节点
        dummy.next = root.right;
        if (root.left != null) {
            dummy.next = root.left;
            root.left.next = root.right;
        }
        
        Node pre;                   // 在下层移动
        while (parent != null) {
            pre = dummy;
            while (parent != null) {
                if (parent.left != null) {
                    pre.next = parent.left;
                    pre = pre.next;
                }
                
                if (parent.right != null) {
                    pre.next = parent.right;
                    pre = pre.next;
                }
                
                parent = parent.next;
            }
            parent = dummy.next;   
            dummy.next = null;         
        }
        return root;
    }

```
