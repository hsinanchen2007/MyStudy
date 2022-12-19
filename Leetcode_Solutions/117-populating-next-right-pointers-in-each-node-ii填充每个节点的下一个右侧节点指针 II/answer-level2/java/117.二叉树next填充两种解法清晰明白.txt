```java
    /**
     * 递归法
     * 执行用时 : 0 ms , 100.00%
     * 内存消耗 : 37.5 MB , 100.00%
     */
    public Node connect(Node root) {
        if (root == null) return null;
        if (root.left != null)
            root.left.next = root.right != null ? root.right : findLeft(root.next);
        if (root.right != null)
            root.right.next = findLeft(root.next);
        //一定要先右后左, 否则会出现构建左侧子树的next时,
        // 右侧子树next还未构建,会得到root的最左子节点为null.
        connect(root.right);  // KEYPOINT
        connect(root.left);   // KEYPOINT
        return root;
    }

    private Node findLeft(Node root) {
        while (root != null) {  //KEYPOINT
            if (root.left != null) return root.left;
            if (root.right != null) return root.right;
            root = root.next;
        }
        return null;
    }

    /**
     * BFS 空间复杂度不满足, 可以看看思路
     * 执行用时 : 2 ms , 56.08%
     * 内存消耗 : 37.8 MB , 100.00%
     */
    public Node connect1(Node root) {
        if (root == null) return null;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        int curLvlNum = 1;
        int nextLvlNum = 0;
        Node curNode, preNode = null;
        boolean first = true;
        while (!queue.isEmpty()) {
            curNode = queue.poll();
            if (curNode.left != null) {
                nextLvlNum++;
                queue.offer(curNode.left);
            }
            if (curNode.right != null) {
                nextLvlNum++;
                queue.offer(curNode.right);
            }
            if (curLvlNum > 0) {
                if (first) {
                    preNode = curNode;
                    first = false;
                } else {
                    preNode.next = curNode;
                    preNode = preNode.next;
                }
            }
            if (--curLvlNum == 0) {
                curLvlNum = nextLvlNum;
                nextLvlNum = 0;
                first = true;
            }
        }
        return root;
    }
```
