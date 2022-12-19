```
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        if(root==NULL) return res;

        stack<TreeNode*> s;
        TreeNode* p = root;
        int curIndex = 0;
        while(!s.empty() || p!=NULL){
            while(p!=NULL){
                if(p->val!=voyage[curIndex]){
                    vector<int> tmp;
                    tmp.push_back(-1);
                    return tmp;
                }
                
                if(p->left!=NULL && p->left->val != voyage[curIndex+1]){
                    if(p->right!=NULL && p->right->val != voyage[curIndex+1]){
                        vector<int> tmp;
                        tmp.push_back(-1);
                        return tmp;
                    }else if(p->right!=NULL && p->right->val == voyage[curIndex+1]){

                        TreeNode* left = p->left;
                        p->left = p->right;
                        p->right = left;
                        res.push_back(p->val);
    
                    }
                }
                curIndex++;
                s.push(p);
                p = p->left;
            }
            TreeNode* topNode = s.top();
            s.pop();
            p = topNode->right;
        }
        return res;
    }
};
```
