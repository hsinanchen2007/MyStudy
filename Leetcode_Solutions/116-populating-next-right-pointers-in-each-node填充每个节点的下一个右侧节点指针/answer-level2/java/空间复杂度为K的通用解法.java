### 空间复杂度为k的解法

我们可以用一个数组floor来保存每层链表的最后一个元素，这样空间复杂度只与树的深度k有关；在遍历的过程中，每次读到一个节点，先将floor中保存的当前层中的元素next指针指向新读入的节点。循环往复。

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    Node[] floor;
    public Node connect(Node root) {
        int k = 0;
        Node n = root;
        while(n!=null){
            k++;
            if(n.left==null && n.right==null){
                break;
            }
            if(n.left != null){
                n = n.left;
            }
            else{
                n = n.right;
            }
        }
        floor = new Node[k];
        func(root,0);
        return root;
    }
    public void func(Node root,int dep){
        if(root==null){
            return;
        }
        if(floor[dep]==null){
            floor[dep]=root;
        }
        else{
            floor[dep].next = root;
            floor[dep] = root;
        }
        func(root.left, dep+1);
        func(root.right, dep+1);
    }
}
```