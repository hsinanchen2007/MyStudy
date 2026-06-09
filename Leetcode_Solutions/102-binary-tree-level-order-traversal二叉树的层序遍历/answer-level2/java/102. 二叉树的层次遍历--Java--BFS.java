[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_102_levelOrder.java)

```java
    /**
     * 解题思路：
     * 按层次遍历，类似于BFS，用一个队列保存遍历结果
     * 1.将（根）节点存入队列
     * 2.将队列中数据取空
     * 3.将取出的treeNode的左右子树存入队列并将结果存入结果集
     * 4.重复1-3直到队列无数据
     * 
     * 优化：可以把2-3合并成一步，你会咋弄？
     *
     * @param root
     * @return
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        Queue<TreeNode> queue = new ArrayDeque<>();
        //1
        queue.add(root);
        //4
        while (!queue.isEmpty()) {
            List<TreeNode> list = new ArrayList<>();
            //2
            while (!queue.isEmpty()) {
                list.add(queue.poll());
            }
            //3
            if (list.size() > 0) {
                List<Integer> addList = new ArrayList<>();
                for (int i = 0; i < list.size(); i++) {
                    TreeNode treeNode = list.get(i);
                    addList.add(treeNode.val);
                    if (treeNode.left != null) queue.add(treeNode.left);
                    if (treeNode.right != null) queue.add(treeNode.right);
                }
                result.add(addList);
            }
        }
        return result;
    }
```