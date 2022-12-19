```
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<int>v1;
        vector<vector<int>>v2;
        if(root==NULL) return v2;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            v1.clear();
            while(cnt--){
              Node *tmp=q.front();
              v1.push_back(tmp->val);
              q.pop();
              for(int i=0;i<tmp->children.size();i++){
                  q.push(tmp->children[i]);
              }
            }
            v2.push_back(v1);
        }
        return v2;
    }
};
