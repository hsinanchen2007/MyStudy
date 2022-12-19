# 前序变成后序，其余思路一致
只需将后序的最后一个作为根，然后先递归构造右树，再递归构造左树
代码如下
```
class Solution {
public:
    // start from first preorder element 前序遍历的迭代器
    int post_idx = 0;
    vector<int> post;
    map<int,int> idx_map;
    TreeNode* helper(int in_left,int in_right)
    {
        // if there is no elements to construct subtrees 如果没有元素来构造树
        if(in_left == in_right)
            return NULL;        
        
        // pick up pre_idx element as a root 选取前序遍历中的值来构造树        
        TreeNode* root = new TreeNode(post[post_idx]);        
        
        // root splits inorder list 根将中序遍历分成左右两部分
        // into left and right subtrees
        auto iter = idx_map.find(post[post_idx]);
        int index = iter->second;        
        
        // recursion 递归
        post_idx--;        
        // build right subtree 生成右树
        root->right = helper(index+1,in_right);
        // build left subtree 生成左树
        root->left = helper(in_left,index);
        
        return root;        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        post_idx = post.size()-1;
        if(post_idx == -1)
            return NULL;
        
        // build a hashmap value -> its index 构造map，储存中序遍历的值和位置
        int idx = 0;
        auto i = inorder.begin();
        for(i;i!=inorder.end();i++){
            idx_map.insert(pair<int,int>(*i,idx++));
        }        
        
        return helper(0,inorder.size()); 
    }
};
```

