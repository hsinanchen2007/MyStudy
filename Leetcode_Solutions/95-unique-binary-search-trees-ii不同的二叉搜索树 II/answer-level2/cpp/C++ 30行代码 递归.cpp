C++实现版本！
```
class Solution {
public:
    vector<TreeNode*> helper(int start,int end){
        vector<TreeNode*> ret;
        if(start > end)
            ret.push_back(nullptr);
        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = helper(start,i-1);
            vector<TreeNode*> right = helper(i+1,end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n == 0)
            return ret;    
        ret = helper(1,n);
        return ret;
    }
};
```
