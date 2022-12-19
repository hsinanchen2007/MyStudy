每一层打印的节点个数和二叉树高度相关，为2^h-1个，也就是每一层的节点都有2^h-1个。这里用width表示root最右
其实就是一个满二叉树的打印，每个节点要处于自己对应的位置上。从root开始，每个左右节点，都是**其父节点为根节点的子树的中位数节点**，也就是说left是[root.left_limit,root]区间的中位数，right是[root,root.right_limit]区间的中位数，初始条件下，root.left_limit = 0,root.left_limit = width。
这样就能找到每一层往下一层的递推公式，然后采用层次遍历，每行定位到对应的index，替换掉打印的值即可。

```
   /**
     * 655.输出二叉树构建的类，记录树节点，树下标，当前树为root的左右子树下标
     */
    private class My655Pair{
        TreeNode node;// 树节点
        int index;// 节点的下标
        int leftLimit;// 当前node为root的左界限
        int rightLimit;// 当前node为root的右界限

        My655Pair(TreeNode node, int index,int leftLimit,int rightLimit){
            this.node = node;
            this.index = index;
            this.leftLimit = leftLimit;
            this.rightLimit = rightLimit;
        }
    }

    /**
     * 655.输出二叉树
     * @param root
     * @return
     */
    public List<List<String>> printTree(TreeNode root) {
        // 返回的结果用arrayList
        List<List<String>> printList = new ArrayList<>();
        // 先获取高度
        int depth = depth(root);// 二叉树高度
        int width = (1 << depth) - 1;// 二叉树宽度

        Queue<My655Pair> queue = new LinkedList<>();// 队列遍历
        // root的index
        int rootIndex = width >> 1;
        // root入队列
        queue.offer(new My655Pair(root,rootIndex,0,width));
        // 每一层的打印列表
        List<String> everyFloor = getNewFloorList(width);

        int front = 0;// 记录层数，队头
        int tail = queue.size();// 记录层数，队尾
        // 层次遍历
        while (!queue.isEmpty()){
            My655Pair pair = queue.poll();// 出队列
            front++;// 每出一个元素，队列头部后移
            // 改变当前pair所在list下标的值
            everyFloor.set(pair.index,String.valueOf(pair.node.val));
            if (pair.node.left != null){
                // 左子树不空的处理
                int leftLimit = pair.leftLimit;
                int rightLimit = pair.index;
                int leftIndex = (leftLimit + rightLimit) >> 1;
                // 获取左孩子下标
                My655Pair leftPair = new My655Pair(pair.node.left,leftIndex,leftLimit,rightLimit);
                queue.offer(leftPair);
            }
            if (pair.node.right != null){
                // 右子树不空的处理
                int leftLimit = pair.index;
                int rightLimit = pair.rightLimit;
                int rightIndex = (leftLimit + rightLimit) >> 1;
                My655Pair rightPair = new My655Pair(pair.node.right,rightIndex,leftLimit,rightLimit);
                queue.offer(rightPair);
            }
            // 当前层遍历结束，层数+1，打印数组记录，重新初始化
            if (front == tail){
                printList.add(everyFloor);// 打印数组记录
                everyFloor = getNewFloorList(width);// 获取新的数组
                front = 0;// 进入下一层，初始化
                tail = queue.size();// 进入下一层，初始化
            }
        }
        return printList;
    }

    /**
     * 获取节点的深度
     * @param root
     * @return
     */
    private int depth(TreeNode root){
        if (root == null){
            return 0;
        }
        int left = depth(root.left);
        int right = depth(root.right);
        return 1 + Math.max(left,right);
    }
    
    /**
     * 获取新的初始化打印List
     * @param width
     * @return
     */
    private List<String> getNewFloorList(int width){
        List<String> everyFloor = new ArrayList<>(width);
        for(int i = 0;i<width;i++){
            everyFloor.add("");
        }
        return everyFloor;
    }
```
