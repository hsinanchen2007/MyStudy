```
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        vector<Node*> m(101,NULL);
        queue<Node*> que;
        m[1] = new Node(node->val);
        que.push(node);
        while(!que.empty()){
            auto p = que.front();
            que.pop();
            for(auto& x:p->neighbors){
                if(!m[x->val]){
                    m[x->val] = new Node(x->val);
                    que.push(x);
                }
                m[p->val]->neighbors.push_back(m[x->val]);
            }
        }
        return m[1];
    }
};
```
