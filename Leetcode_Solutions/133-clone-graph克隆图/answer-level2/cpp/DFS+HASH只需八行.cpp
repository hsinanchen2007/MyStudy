深层拷贝，举例：存储节点1的地址原本0x0001，和新节点地址0x1001，两者之间需要建立关系。
```
class Solution {
    unordered_map<Node*,Node*> dict;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(dict.count(node)) return dict[node];
        Node *copy = dict[node] = new Node(node->val, vector<Node*>());
        for(const auto &n:node->neighbors){
            copy->neighbors.push_back(cloneGraph(n));
        }
        return copy;
    }
};
```
