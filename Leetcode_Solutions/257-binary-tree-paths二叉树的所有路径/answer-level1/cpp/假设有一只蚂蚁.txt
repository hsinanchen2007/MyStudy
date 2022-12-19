假设有一只蚂蚁，肩上驮着她所经过的节点的字符串表示，一旦他发现到达了叶子节点，就向长官报告，
```
class Solution {
public:
    void helper(TreeNode* root, vector<string>& v, string s){
        if(root == NULL) return; //如果达到了空节点就回去
        s+= "->";
        s += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            //一旦发现叶子节点就向长官报告
            v.push_back(s);
            return;
        }
        
        helper(root->left, v, s);
        helper(root->right, v, s);
        
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == NULL) return v;
        if(root->right == NULL && root->left == NULL){
            v.push_back(to_string(root->val));
            return v;
        }
        //上面几行处理root的几个特殊情况

        string s = to_string(root->val);
        helper(root->left, v, s);
        helper(root->right, v,s);
        return v;
        
    }
};
```
