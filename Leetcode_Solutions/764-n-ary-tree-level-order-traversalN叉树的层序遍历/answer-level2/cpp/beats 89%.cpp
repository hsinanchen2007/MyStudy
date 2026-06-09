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
        vector<vector<int>> tree;
        if(!root)
            return tree;
        vector<Node*> this_level;
        vector<int> this_level_val;
        vector<Node*> next_level;
        this_level.push_back(root);
        while(!this_level.empty()){
            this_level_val.clear();
            for(auto leave:this_level){
                this_level_val.push_back(leave->val);
                for(auto c:leave->children)
                    next_level.push_back(c);
            }
            tree.push_back(this_level_val);
            this_level=next_level;
            next_level.clear();
            
        }
        return tree;
    }
};
```
