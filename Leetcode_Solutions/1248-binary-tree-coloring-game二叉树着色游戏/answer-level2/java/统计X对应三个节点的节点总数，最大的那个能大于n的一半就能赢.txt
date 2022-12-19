
### 解题思路
统计X对应三个节点的节点总数，最大的那个能大于n/2就能赢

1.找到x所在节点的位置
2.统计左子树节点，右子树节点，非X子树节点的个数
3.三者只要有一个能>n/2就可以稳赢

### 代码
```java
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        if (root == null){
            return false;
        }
        // 1.找到x所在节点
        TreeNode node = findXNode(root,x);
        // 2.统计x左节点总数和x右节点总数
        int leftCount = nodeCount(node.left);
        int rightCount = nodeCount(node.right);
        // 3.从左，右，非x子树（父）的节点数中，找到最大的数字，看是否大于n/2
        int parentCount = n - leftCount - rightCount - 1;// 属于父节点的节点总数
        int winCount = n >> 1;// 获胜的数字
        int maxCount = Math.max(Math.max(leftCount,rightCount),parentCount);// 三个选择点最大的计数
        return maxCount > winCount ;
    }

    /**
     * 找到x所在的节点，层次遍历寻找
     * @param root
     * @param x
     * @return
     */
    private TreeNode findXNode(TreeNode root,int x){
        TreeNode node = root;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(node);
        boolean find_x = false;
        while (!queue.isEmpty()){
            node = queue.poll();
            if (node.val == x){
                find_x = true;
                break;
            }
            if (node.left != null){
                queue.offer(node.left);
            }
            if (node.right != null){
                queue.offer(node.right);
            }
        }
        if (find_x){
            return node;
        }else{
            return null;
        }
    }

    /**
     * 节点数统计
     * @param node
     * @return
     */
    private int nodeCount(TreeNode node){
        if (node == null){
            return 0;
        }
        return 1 + nodeCount(node.left) + nodeCount(node.right);
    }
```
