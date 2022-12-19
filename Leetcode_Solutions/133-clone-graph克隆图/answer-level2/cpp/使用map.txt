使用一个map 分别对应新的和旧的节点
第一次遍历找出所有的node 并且 创建新的节点，并记录到map中。
第二次遍历所有的旧点，将新的节点中的邻居vector 替换成新的。

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    void dfs(Node *cur,map<Node*,Node*> &mp,map<Node*,bool> &visited){
        Node *nn=new Node(cur->val,vector<Node*>());
        mp[cur]=nn;
        for (auto node:cur->neighbors){
            if (visited.find(node)==visited.end()){
                visited[node]=true;
                dfs(node,mp,visited);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        vector<Node*> nodes;
        map<Node*,Node*> mp;
        map<Node*,bool> visited;
        dfs(node,mp,visited);
        for (auto nn=mp.begin();nn!=mp.end();nn++){
            Node* old=nn->first;
            Node* newn=nn->second;
            
            for (Node* nei:old->neighbors){
                newn->neighbors.push_back(mp[nei]);
            }

        }
        return mp[node];
        
    }
};
```

