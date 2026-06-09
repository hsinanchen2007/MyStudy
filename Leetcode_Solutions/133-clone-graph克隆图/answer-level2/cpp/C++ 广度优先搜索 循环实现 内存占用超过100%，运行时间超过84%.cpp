如果使用深度优先搜索，只需要将queue改用为stack即可。
思路：
1 广度优先遍历整个图（使用queue）
1.1 已遍历的节点值存在set内，防止重复访问，未遍历的邻节点才存到queue内，以queue为空作为遍历结束标志；
1.2 复制每一个节点，值复制，其相邻节点指针使用原始节点指针；
1.3 将新节点指针保存在set内，老节点新节点的指针对应关系存在map表内；
2 遍历新节点的set，将其邻节点指针使用新老节点的map表对应关系进行替换。

具体代码：（变量命名有点迷，说明编程规范还是没有刻入骨髓啊）
```c
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
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
        {
            return node;
        }
        if(node->neighbors.empty())
        {
            return new Node(node->val);
        }
        Node* resNode = nullptr;// 存返回值
        set<int> valSet;
        queue<Node*> queueNode;
        queueNode.push(node);
        map<Node*, Node*> oldNewMapNode;
        set<Node*> setNewNode;
        while(!queueNode.empty())
        {
            Node* tempNode = queueNode.front();
            queueNode.pop();
            Node* copyNode = new Node(tempNode->val, tempNode->neighbors);
            if(!resNode)
            {
                resNode = copyNode;
            }
            valSet.insert(copyNode->val);
            setNewNode.insert(copyNode);
            oldNewMapNode[tempNode] = copyNode;
            for(int i = 0; i < copyNode->neighbors.size(); i++)
            {
                if(valSet.find(copyNode->neighbors[i]->val) == valSet.end())
                {
                    queueNode.push(copyNode->neighbors[i]);
                }
            }
        }
        for(set<Node*>::iterator iter = setNewNode.begin(); iter != setNewNode.end(); ++iter)
        {
            for(int i = 0; i < (*iter)->neighbors.size(); i++)
            {
                (*iter)->neighbors[i] = oldNewMapNode.find((*iter)->neighbors[i])->second;
            }
        }
        return resNode;
    }
};
```
