### 解题思路

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
class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        if(!node) return NULL;
        vector<Node*> addr(101,NULL);
        Node* New=new Node(node->val);
        addr[1]=New;
        return clone(New,node,addr);
    }

    Node* clone(Node* New,Node* Old,vector<Node*>& addr)
    {
        for(int i=0;i<Old->neighbors.size();i++)
        {
            //邻居地址不为0,则直接加入即可
            if(addr[Old->neighbors[i]->val])
            {
                New->neighbors.push_back(addr[Old->neighbors[i]->val]);
                continue;
            }

            //邻居地址为0,则创建后加入,再深入(递归)
            addr[Old->neighbors[i]->val]=new Node(Old->neighbors[i]->val);
            New->neighbors.push_back(addr[Old->neighbors[i]->val]);
            New->neighbors[i]=clone(New->neighbors[i],Old->neighbors[i],addr);
        }

        return New;
    }
};
```

![无标题.png](https://pic.leetcode-cn.com/cb1a7b75a82ae1f8c9bad537ad954a20bb5442688cae2ec79cb13387763a3592-%E6%97%A0%E6%A0%87%E9%A2%98.png)


