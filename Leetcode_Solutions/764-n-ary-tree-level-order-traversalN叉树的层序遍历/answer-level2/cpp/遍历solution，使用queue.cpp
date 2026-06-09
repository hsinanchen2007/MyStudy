同时建议做一下102和107，很类似的。
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        
        queue<Node*> que;
        que.push(root);
        int len = 1;
        
        while(que.size()){
            vector<int> pres;
            len = que.size();
            while(len){
                Node* tmp;
                tmp = que.front();
                pres.push_back(tmp->val);
                for(auto child : tmp->children){
                    que.push(child);
                }
                que.pop();
                len --;
            }
            result.push_back(pres);
        }
        return result;
    }
};
```
