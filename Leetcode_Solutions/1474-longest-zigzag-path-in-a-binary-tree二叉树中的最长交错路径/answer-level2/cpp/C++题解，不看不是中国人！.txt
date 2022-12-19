函数返回的是 {当前节点的左交错路径长度，当前节点的右交错路径长度}
递归主体显而易见： 当前节点左交错路径长度 = 1 + 左子树的右交错路径长度
                当前节点右交错路径长度 = 1 + 右子树的左交错路径长度
递归出口特判 {-1， -1}


    int ans = 0;
    
    int longestZigZag(TreeNode* root) {
        func(root);
        return ans;
    }
    
    pair<int, int> func(TreeNode* root) {
        if(!root)   return make_pair(-1, -1);
        pair<int, int> l = func(root->left);
        pair<int, int> r = func(root->right);
        // printf("%d : [%d, %d]\n", root->val, l.second + 1, r.first + 1);
        ans = max(ans, l.second + 1), ans = max(ans, r.first + 1);
        return make_pair(l.second + 1, r.first + 1);
    }
