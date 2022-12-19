基本思路：从上到下，按层，按照左中顺序依次将节点存入list即可。
```
public List<Integer> inorderTraversal4(TreeNode root) {
        //方法3的优化版：试着不用noNodes, 左右add后，将left right置为空即可
        List<Integer> list = new ArrayList<>();
        //1.
        if (root == null) {
            return list;
        }
        //2. 迭代
        List<TreeNode> nodes = new ArrayList<>();
        nodes.add(root);
        //记录当前层是否还有分支
        boolean hasBranch = true;
        while (hasBranch) {
            hasBranch = false;
            //按层遍历
            for (int i = 0; i < nodes.size(); i++) {
                TreeNode node = nodes.get(i);
                hasBranch = hasBranch || !(node.left == null && node.right == null);
                //分别将left 和right插入到node的左右
                if (node.left != null) {
                    nodes.add(i++, node.left);
                    //left置为空
                    node.left = null;
                }
                if (node.right != null) {
                    nodes.add(++i, node.right);
                    //right置为空
                    node.right = null;
                }
            }
        }
        //3. 遍历nodes即可
        for (TreeNode node : nodes) {
            list.add(node.val);
        }
        return list;
    }
```
