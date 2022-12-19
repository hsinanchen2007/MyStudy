

```

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*, Node *> mmap;
        Node *head=new Node(node->val);
        mmap[node] = head;
        queue<Node *> q;
        q.push(node);
        while(!q.empty()){
            Node *tmp = q.front();
            q.pop();
            for(auto neighbor_node:tmp->neighbors){
                if(mmap.find(neighbor_node)==mmap.end()){
                    mmap[neighbor_node] = new Node(neighbor_node->val);
                    q.push(neighbor_node);
                }
                mmap[tmp]->neighbors.push_back(mmap[neighbor_node]);
            }
        }

        return head;
    }
};
```
