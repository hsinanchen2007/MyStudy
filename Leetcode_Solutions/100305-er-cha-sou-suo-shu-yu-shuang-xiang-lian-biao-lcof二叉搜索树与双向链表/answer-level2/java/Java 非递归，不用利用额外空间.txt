利用二叉树的Morris遍历
```
    public Node treeToDoublyList(Node root) {
        if(root==null){
            return root;
        }
        Node p = root;
        Node head = null;
        Node pre = null;
        while(p!=null){
            while(p.left!=null){
                Node q = p.left;
                while (q.right!=null){
                    q=q.right;
                }
                q.right = p;
                Node t=p.left;
                p.left = null;
                p=t;
            }
            p.left = pre;
            if (pre == null){
                head = p;
            }else{
                pre.right = p;
            }
            pre = p;
            p = p.right;
        }
        pre.right = head;
        head.left = pre;
        return head;
    }
```
