```
   /**
     * 二叉树最近公共祖先
     *
     * 时间复杂度O(n)
     * 空间复杂度O(n)
     *
     * 思路：
     *
     * 1.遍历二叉树将每个节点的最近父节点关联，存入map中（key为子节点，value为最近父节点）
     * 2.将节点p的所以父节点存入hashSet中
     * 3.遍历节点q的所有父节点（最近->最远）直到父节点存在在节点p的父节点集合中，
     *   返回父节点即为p、q最近公共祖先
     *
     * @param root 根节点
     * @param p    节点p
     * @param q    节点q
     * @return 最近公共祖先
     */
    private static TreeNode searchPublicParentNode(TreeNode root, TreeNode p, TreeNode q) {
        //节点和其最近父节点的map
        HashMap<TreeNode, TreeNode> parent = new HashMap<>();
        //根节点的父节点为null
        parent.put(root, null);
        //1.借助queue遍历二叉树
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                //存入节点和其最近父节点
                parent.put(node.left, node);
                queue.add(node.left);
            }
            if (node.right != null) {
                //存入节点和其最近父节点
                parent.put(node.right, node);
                queue.add(node.right);
            }
        }
        //节点p所有父节点集合
        HashSet<TreeNode> set = new HashSet<>();
        while (p != null) {
            //遍历节点p的所有父节点
            set.add(p);
            p = parent.get(p);
        }

        //遍历节点q的所有父节点，直到q的父节点出现在p的父节点集合中
        //返回q即为pq最近祖先
        while (!set.contains(q)) {
            q = parent.get(q);
        }

        return q;

    }
```
