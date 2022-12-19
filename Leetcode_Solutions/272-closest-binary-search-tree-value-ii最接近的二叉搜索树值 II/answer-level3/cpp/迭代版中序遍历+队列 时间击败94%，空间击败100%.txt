```
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        queue<int> q;
        stack<TreeNode*> s;
        TreeNode* node = root;
        do{
            while(node){
                s.push(node);
                node = node->left;                
            }
            node = s.top();
            s.pop();
            if(q.size() < k || abs(q.front() - target) > abs(node->val - target))
                q.push(node->val);
            else
                break;
            if(q.size() > k)
                q.pop();
            
            node = node->right;
        }while(!s.empty() || node);
        for(int i = 0; i < k; i++){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
```
