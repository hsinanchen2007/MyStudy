![image.png](https://pic.leetcode-cn.com/0fb16e6665d8618c48b33f312747041c73573ccaaf075b5cdbde0a64b1c6d872-image.png)

### 代码

```java
class Solution {
    public Node treeToDoublyList(Node root) {
        if(root == null) return null;
        Node[] tmp = method(root);
        tmp[0].left = tmp[1];
        tmp[1].right = tmp[0];
        return tmp[0];

    }

    //这是一个方法能够返回 一个树的头结点和尾结点组成的结点数组，并且进行互连操作
    public Node[] method(Node root) {
        if (root.left == null && root.right == null) {
            return new Node[]{root, root};
        }
        if(root.left == null){
            Node[] tmp = method(root.right);
            root.right = tmp[0];
            tmp[0].left = root;
            return new Node[] {root, tmp[1]};
        }
        if(root.right == null){
            Node[] tmp = method(root.left);
            tmp[1].right = root;
            root.left = tmp[1];
            return new Node[]{tmp[0], root};
        }
        Node[] tmpLeft = method(root.left);
        Node[] tmpRight = method(root.right);
        tmpLeft[1].right = root;
        root.left = tmpLeft[1];
        root.right = tmpRight[0];
        tmpRight[0].left = root;
        return new Node[]{tmpLeft[0], tmpRight[1]};
    }

}

```