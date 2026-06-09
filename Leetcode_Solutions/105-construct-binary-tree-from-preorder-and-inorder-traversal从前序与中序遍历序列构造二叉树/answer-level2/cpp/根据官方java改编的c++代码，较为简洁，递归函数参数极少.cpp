# 简洁官方Java代码改编版c++
思路与官方题解一致，看官方题解即可。代码结构与官方差不多，递归函数的参数极少，看起来更加舒适。
```
class Solution {
public:
    // start from first preorder element 前序遍历的迭代器
    int pre_idx = 0;
    vector<int> pre;
    map<int,int> idx_map;
    TreeNode* helper(int in_left,int in_right)
    {
        // if there is no elements to construct subtrees 如果没有元素来构造树
        if(in_left == in_right)
            return NULL;        
        
        // pick up pre_idx element as a root 选取前序遍历中的值来构造树        
        TreeNode* root = new TreeNode(pre[pre_idx]);        
        
        // root splits inorder list 根将中序遍历分成左右两部分
        // into left and right subtrees        
        auto iter = idx_map.find(pre[pre_idx]);
        int index = iter->second;        
        // recursion 递归
        
        pre_idx++;
        // build left subtree 生成左树
        root->left = helper(in_left,index);
        // build right subtree 生成右树
        root->right = helper(++index,in_right);
        
        return root;        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;        
        
        // build a hashmap value -> its index 构造map，储存中序遍历的值和位置
        int idx = 0;        
        for(auto i = inorder.begin(); i!=inorder.end(); i++){
            idx_map.insert(pair<int,int>(*i,idx++));
        }        
        return helper(0,inorder.size());        
    }
};
```
