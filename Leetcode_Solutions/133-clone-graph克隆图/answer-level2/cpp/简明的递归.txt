### 解题思路
麻烦的地方：邻接节点是指针，想复制父节点必须先复制子节点，想到递归
方便的地方：val是unique的，可以作为哈希表的键值

### 代码

```cpp
class Solution {
public:
    Node* cloneGraph_core(Node* node, unordered_map<int, Node*>& mp) {
        Node* newNode = new Node();
        mp[node->val] = newNode;
        vector<Node*> nbrs;
        for (int i=0; i<node->neighbors.size(); i++) {
            //该节点没有被复制过，需要复制
            if (mp.find(node->neighbors[i]->val) == mp.end())
                nbrs.push_back(cloneGraph_core(node->neighbors[i], mp));
            //复制过了，直接从表里拿它的指针
            else 
                nbrs.push_back(mp[node->neighbors[i]->val]);
        }
        //更新节点信息
        newNode->val = node->val;
        newNode->neighbors = nbrs;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if (node==NULL) return node;
        unordered_map<int, Node*> mp;
        return cloneGraph_core(node, mp);
    }
};
```