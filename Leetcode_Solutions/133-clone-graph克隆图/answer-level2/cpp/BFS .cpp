1. 用pair来保存新节点与原节点映射关系
2. 用map来保存已经copy过的新节点，一方面避免bfs时无限循环，另一方面避免新图有重复节点
3. 之后按original的bfs，在遍历孩子节点的时候进行节点复制和边复制。

```
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<pair<Node*, Node*>> node_que;
        Node* head = new Node(node->val);
        node_que.push(make_pair(node, head)); 
        map<int, Node*> copied;
        copied[head->val] = head;
        while(!node_que.empty())  
        {
            pair<Node*, Node*> curr = node_que.front();
            node_que.pop();
            Node* old_node = get<0>(curr);
            Node* new_node = get<1>(curr);

            for(auto child : (old_node->neighbors))
            {
                Node* new_child = NULL;
                if(copied.find(child->val) == copied.end())
                {
                    new_child = new Node(child->val);
                    copied[child->val] = new_child;
                    node_que.push(make_pair(child, new_child)); 
                }
                else
                {
                    new_child = copied[child->val];
                }
                (new_node->neighbors).push_back(new_child);
            }
        } 
        return head; 
    }
};
```
