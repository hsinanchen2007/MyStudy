    int kthSmallest(TreeNode* root, int k) {
        int val = 0;    //k最小值
        int curr = 0;    //当前遍历的序号
        inOrder(root, curr, k, val);    //中序遍历，生成从小到大的顺序
        return val;    
    }
    
    void inOrder(TreeNode* root, int& curr, int k, int& val) //curr保持递归内全局变量，val保持最后的数值
    {
        if (!root)    //空树
            return;    //返回
        inOrder(root -> left, curr, k, val);    //中序遍历左子树
        curr ++;    //最左元素表示第一个元素,序号加1，每次遍历到root，就是一次最小值。
        if (curr == k)    //序号等于k
        {
            val = root -> val;    //保存当前元素
        }
        inOrder(root -> right, curr, k, val);    //中序遍历右子树
    }