本题的关键在于理解preorder表和inorder表在建树中各自起到的作用。
inorder表：维护了左右子树与根节点的关系，因此可以基于它来划分子任务。
preorder表：我们建树的顺序是基于preorder表来建树的，所以preorder表里的第一个值必定是根节点，因此可以基于它来取当前节点的值。
另外一个关键点是，在建树过程中要维护一个全局变量first，来记录当前build的是第几个节点，这个first的值与preorder表的顺序是一致的。
```c++
class Solution {
public:
    unordered_map<int,int> idx_map;
    int first = 0;
    //[关键点] 用inorder来划分建树，用preorder来取第一个数作为根节点值，因此要有一个全局的global的first变量来记录build的是第几个节点。
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int lo, int hi) {
        int l = hi - lo;
        if (l <= 0) return NULL;
        //用preorder表来取根节点的值
        int rootval = preorder[first];
        TreeNode* root = new TreeNode(rootval);
        first += 1; // recursive
        if (l == 1) return root;

        //基于inorder表划分左子树
        root->left = dfs(preorder, inorder, lo, idx_map[rootval]); 

        //基于inorder表划分右子树
        root->right = dfs(preorder, inorder, idx_map[rootval]+1, hi);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) idx_map[inorder[i]] = i;
        return dfs(preorder, inorder, 0, inorder.size());
    }
};
```
