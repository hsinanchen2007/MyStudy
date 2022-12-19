```java

import java.util.*;

class Node {
    int val;
    Node l;
    Node r;

    Node(int i) {
        val = i;
        this.l = null;
        this.r = null;
    }
}

class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        //1、先构造一个二叉树的问题
        // A处：构造时注意自环，
        // B处：以及同一结点的二次new(),利用hashmap判重，保证同一个结点只被new一次
        HashMap<Integer, Node> map = new HashMap<>(n);
        for (int i = 0; i < n; ++i) {
            if (i == leftChild[i] || i == rightChild[i]) return false;//A
            Node root = map.get(i);
            if (root == null)//B
                root = new Node(i);
            if (leftChild[i] != -1) {
                root.l = map.get(leftChild[i]);
                if (root.l == null) {//B
                    root.l = new Node(leftChild[i]);
                    map.put(leftChild[i], root.l);
                }
            }
            if (rightChild[i] != -1) {
                root.r = map.get(rightChild[i]);
                if (root.r == null) {//B
                    root.r = new Node(rightChild[i]);
                    map.put(rightChild[i], root.r);
                }
            }
            map.put(i, root);
        }
        boolean rst = false;
        //2、BFS自顶向下搜索
        //C处:判断是否存在回路 或 一个子节点同时被两上父节点指向
        //D处：默认是根节点不一定是0,可以是别的节点，所以需要遍历
        for (Integer key : map.keySet()) {//D
            Node root = map.get(key);
            Queue<Node> Q = new LinkedList<>();
            Q.add(root);
            boolean F[] = new boolean[n];
            while (!Q.isEmpty()) {
                root = Q.remove();
                if (F[root.val]) return false;//C
                F[root.val] = true;
                if (root.l != null) Q.add(root.l);
                if (root.r != null) Q.add(root.r);
            }
            int i = 0;
            for (; i < F.length; ++i) {
                if (!F[i]) break;
            }
            if (i == F.length) {
                rst = true;
                break;
            }
        }
        return rst;
    }
}
```