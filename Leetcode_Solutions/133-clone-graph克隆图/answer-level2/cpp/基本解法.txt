### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)   return nullptr;
        Node* a=new Node();
        a->val=node->val;
        if(mp.count(node)==0) mp[node]=a;        
        for(int i=0;i<node->neighbors.size();i++)
        {  
             if(mp.count(node->neighbors[i])==1)
             a->neighbors.push_back(mp[node->neighbors[i]]);
             else 
             a->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }

        return a;
    }

};
//深度遍历也是一个递归；

```