```
class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        root.next = null;
        Node ptr = root; // 用于遍历每一层的指针
        Node levelHead = root;//定位层
        while (levelHead != null && levelHead.left != null) {
            ptr = levelHead;
            while (ptr != null) { //从每层的第一个节点开始调整他们子节点的next指针
                ptr.left.next = ptr.right;
                if (ptr.next == null) 
                    ptr.right.next = null;
                else
                    ptr.right.next = ptr.next.left;
                ptr = ptr.next;
            }
            levelHead = levelHead.left;
        }
        return root;
    }
}
```
