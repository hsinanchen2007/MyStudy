```
    Node flatten(Node head) {
        flattenTail(head);
        return head;
    }

    private Node flattenTail(Node root) {
        if(root == null) return null;
        Node leftTail = flattenTail(root.child);
        Node rightTail = flattenTail(root.next);
        if(root.child!=null) {//只有当左子树存在时才将它插入右子树中
            Node temp = root.next;
            root.next = root.child;
            root.child.prev = root;
            root.child = null;
            leftTail.next = temp;
            if (temp!=null) //注意root的next可能是null, 这里面要剔除这种情况
            temp.prev = leftTail;
        }

        //返回尾部元素时，需要特殊处理
        // (1) 有右子树的情况
        if(rightTail!=null) return rightTail;
        // (2) 无右子树但有左子树的情况
        if(leftTail!=null) return leftTail;
        // (3)左右子树均不存在的情况。
        return root;
    
```

思路参考 http://bangbingsyb.blogspot.com/2014/11/leetcode-flatten-binary-tree-to-linked.html
