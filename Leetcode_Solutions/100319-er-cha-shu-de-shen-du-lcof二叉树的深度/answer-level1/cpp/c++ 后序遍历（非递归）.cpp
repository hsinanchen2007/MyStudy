```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int max = 0;
        TreeNode* p = root;
        while(p != NULL || !s.empty()){
            while(p != NULL){
                s.push(p);
                p = p->left;
            }

            p = s.top();
            TreeNode* tmp = NULL;
            max = max > s.size() ? max : s.size();
            while(!s.empty() && (p->right == NULL || p->right == tmp)){
                s.pop();
                if(!s.empty()){
                    tmp = p;
                    p = s.top();
                }
            }

            if(s.empty()) break;
            p = p->right;
        }
        return max;
    }
private:
    stack<TreeNode*> s;
};
```
