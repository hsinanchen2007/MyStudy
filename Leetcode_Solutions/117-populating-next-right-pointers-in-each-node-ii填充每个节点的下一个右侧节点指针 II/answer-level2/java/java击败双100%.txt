### 代码

```java
class Solution {
    public Node connect(Node root) {
        if(root==null||(root.left==null&&root.right==null))
            return root;
        //先遍历右侧子节点
        if(root.right!=null){
            root.right.next = getNeareast(root.next);
            connect(root.right);
        }
        //再遍历左侧子节点
        if(root.left!=null){
            root.left.next = root.right==null?getNeareast(root.next):root.right;
            connect(root.left);
        }
        return root;
    }
    //获得同层的的下一个节点
    private Node getNeareast(Node cur){
        while(cur!=null){
            if(cur.left!=null)
                return cur.left;
            if(cur.right!=null)
                return cur.right;
            cur = cur.next;
        }
        return null;
    }
}
```