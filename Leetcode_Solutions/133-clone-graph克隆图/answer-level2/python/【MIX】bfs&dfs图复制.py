### 解题思路
1. 遍历顶点存储映射关系
2. 复制邻边关系

### 代码

**bfs**
```java []
class Solution {
    public Node cloneGraph(Node node) {
        if(node == null)
            return node;
        HashMap<Node, Node> rec = new HashMap<>();
        Queue<Node> q = new LinkedList<>();

        rec.put(node, new Node(node.val));
        q.offer(node);

        while(!q.isEmpty()){
            Node _node = q.poll();
            for(Node nei : _node.neighbors){
                if(!rec.containsKey(nei)){
                    q.offer(nei);
                    rec.put(nei, new Node(nei.val));
                }
                rec.get(_node).neighbors.add(rec.get(nei));
            }
        }
        return rec.get(node);
    }
}
```
```python []
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        # bfs
        if node == None:
            return
        
        rec = dict({node: Node(node.val)})
        q = list([node])
        
        while len(q) > 0:
            _node = q.pop(0)
            for nei in _node.neighbors:
                if nei not in rec.keys():
                    rec[nei] = Node(nei.val)
                    q.append(nei)

                rec[_node].neighbors.append(rec[nei])
        
        return rec[node]
```
```c++ []
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;

        unordered_map<Node*, Node*> rec;
        queue<Node *> q({node});
        rec[node] = new Node(node->val);
    
        // bfs
        while(!q.empty()){
            Node *_node = q.front();
            q.pop();
            for(Node *nei : _node->neighbors){
                if(rec.find(nei) == rec.end()){
                    q.push(nei);
                    rec[nei] = new Node(nei->val);
                }
                rec[_node]->neighbors.push_back(rec[nei]);
            }
        }
        return rec[node];
    }
};
```
**dfs非递归**
```c++ []
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;

        unordered_map<Node*, Node*> rec;
        stack<Node *> st({node});
        rec[node] = new Node(node->val);
    
        // bfs
        while(!st.empty()){
            Node *_node = st.top();
            st.pop();
            for(Node *nei : _node->neighbors){
                if(rec.find(nei) == rec.end()){
                    st.push(nei);
                    rec[nei] = new Node(nei->val);
                }
                rec[_node]->neighbors.push_back(rec[nei]);
            }
        }
        return rec[node];
    }
};
```
**dfs递归**
```java []
class Solution {
    public Node cloneGraph(Node node) {
        // dfs 递归
        if(node == null)
            return null;
        
        if(rec.get(node)!=null)
            return rec.get(node);
            
        rec.put(node, new Node(node.val));
        for(Node nei: node.neighbors){
            rec.get(node).neighbors.add(cloneGraph(nei));
        }

        return rec.get(node);
        
    }

    private HashMap<Node, Node> rec = new HashMap<>();
}
```
```python []
class Solution:
    rec = dict()
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None:
            return node
        if node in self.rec.keys():
            return self.rec[node]
        
        self.rec[node] = Node(node.val)
        for nei in node.neighbors:
            self.rec[node].neighbors.append(self.cloneGraph(nei))

        return self.rec[node]
```
```c++ []
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        if(rec.find(node) != rec.end())
            return rec[node];
        
        rec[node] = new Node(node->val);
        for(auto &_node : node->neighbors){
            rec[node]->neighbors.push_back(cloneGraph(_node));
        }

        return rec[node];
    }

private:
    unordered_map<Node*, Node*> rec;
};
```

