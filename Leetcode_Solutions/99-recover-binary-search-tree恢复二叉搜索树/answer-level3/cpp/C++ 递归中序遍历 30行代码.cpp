中序遍历找规律，升序排列。扫描遍历，发现有降序，把该组节点记录下来。
如果找到一组节点，交换这组节点的值。找到两组节点，把首尾节点的值交换！
```
class Solution {
public:
    TreeNode* pre;
    vector<TreeNode*> v;
    
    void helper(TreeNode* root){
        if(root == nullptr)
            return;
        helper(root -> left);
        
        if(pre -> val > root -> val){
            v.push_back(pre);
            v.push_back(root);
        }
        
        pre = root;
        helper(root -> right);
    }
    
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        
        helper(root);
        if(v.size() == 2){
            int tp = v[0] -> val;
            v[0]->val = v[1]->val;
            v[1]->val = tp;
        }else{
            int tp = v[0]->val;
            v[0]->val = v[3]->val;
            v[3]->val = tp;
        }
    }
};
```

