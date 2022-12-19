1、利用Queue层序遍历，因为需要处理单独一层的数据，因此用size来记录当前层所需处理的元素个数。
2、然后就是用 flag&1 来判断层数的奇偶性，再进行对应的顺序控制即可。
```
    /**
     * 层序遍历变种，用flag来切换不同层的顺序，达到锯齿效果。
     *
     * 如果添加完再逆序，会影响到执行效率。[注释部分]
     */
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) return res;
        LinkedList<TreeNode> q = new LinkedList<>();
        q.addFirst(root);
        int flag = 0;//偶数为 左 -> 右
        while (!q.isEmpty()) {
            int size = q.size();
            LinkedList<Integer> inner = new LinkedList<>();
            for (int i = 0; i < size; i++) {
                TreeNode temp = q.removeFirst();
                // 奇数层反序插入
                if ((flag & 1) == 1) {
                    inner.addFirst(temp.val);
                } else {
                    inner.addLast(temp.val);
                }
                if (temp.left != null) q.addLast(temp.left);
                if (temp.right != null) q.addLast(temp.right);
            }
//            // 奇数
////            if((flag&1) == 1){
////                inner.sort((a,b) -> -1);
////            }
            res.add(inner);
            flag++;
        }
        return res;
    }
```