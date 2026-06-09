### 思路
本题用map来做就非常容易。
```
class Solution {
public:
    map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)   return nullptr;
        if(mp.count(node))  return mp[node];
        Node* c = new Node(node -> val);
        mp[node] = c;
        for(int i = 0; i < node -> nei***ors.size(); ++ i){
            if(node -> nei***ors[i])    c -> neighbors.push_back(cloneGraph(node -> neighbors[i]));
        }
        return c;
    }
};
```
