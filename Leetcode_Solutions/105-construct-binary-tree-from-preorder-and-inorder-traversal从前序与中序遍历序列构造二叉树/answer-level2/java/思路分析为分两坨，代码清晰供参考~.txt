中心思想：
1 利用preorder确定根； 
2 在inorder找到根的位置；
3 通过根在inorder的位置得到左右子树的元素个数；
4 除了根，分为左右两坨，根据左右子树元素个数得到preorder和inorder的递归起始位置；
5 递归求左右分支。
```
    /**
     * 提高运行效率两点：
     * 1、利用map存放根节点在inorder中的索引，缩短查找时间；
     * 2、递归时，不生成新数组，只传递preorder、inorder的开始索引和数组长度。
     * 执行用时 :3 ms, 96.20%
     * 内存消耗 :36.1 MB, 98.06%
     */
    Map<Integer, Integer> map;
    int[] preorder;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null || preorder.length == 0 || inorder.length == 0)
            return null;
        this.map = new HashMap<>();  //定义map存放inorder索引, 减少查找根节点在inorder索引的时间。
        for (int i = 0; i < inorder.length; i++)
            map.put(inorder[i], i);
        this.preorder = preorder;
        return helper(0, 0, preorder.length);
    }

    private TreeNode helper(int pFrom, int iFrom, int length) {
        if (length < 1)
            return null;
        TreeNode root = new TreeNode(preorder[pFrom]);
        if (length == 1)
            return root;
        int rootIdx = map.get(preorder[pFrom]);
        // 分左右两个分支, 递归处理
        int len1 = rootIdx - iFrom;
        int len2 = length - len1 - 1;
        root.left = helper(pFrom + 1, iFrom, len1);
        root.right = helper(pFrom + 1 + len1, rootIdx + 1, len2);
        return root;
    }
```
