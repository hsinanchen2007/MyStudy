### 解题思路
BFS，采用一个map记录新老映射关系，邻居节点没有就创建

### 代码

```cpp
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
    Node* cloneGraph(Node* node) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(node);
        map<Node*, Node*> newoldmap;//<old, new>
        set<Node*> seens;
        seens.insert(node);
        //BFS
        while(!q.empty()){
            Node* cur = q.front();//取出一个老节点
            q.pop();
            Node* newone = NULL;
            map<Node*, Node*>::iterator it1 = newoldmap.find(cur);
            if(it1 == newoldmap.end()){//克隆一个新节点
                newone = new Node(cur->val,  vector<Node*>());
                newoldmap[cur] = newone;//每次创建一个新节点，记录老新节点的映射关系
                if(!res){
                    res = newone;//记录入口
                }
            }else{
                newone = it1->second;
            }
            //克隆邻居节点
            for(int i = 0; i < cur->neighbors.size(); i++){//遍历老节点所有邻居
                Node* neighbor = cur->neighbors[i];
                map<Node*, Node*>::iterator ite = newoldmap.find(neighbor);//映射关系进行查找
                //如果找到映射关系，说明邻居中的新节点已经建立，
                if(ite != newoldmap.end()){
                    (newone->neighbors).push_back(ite->second);//邻居已克隆，添加到邻居列表
                }else{ //如果没找到，说名有的节点还没创建，则创建
                    Node* newneighbor = new Node(neighbor->val, vector<Node*>());
                    newoldmap[neighbor] = newneighbor;
                    (newone->neighbors).push_back(newneighbor);//将新创建的邻居添加到邻居列表
                }
                if(seens.find(cur->neighbors[i]) == seens.end()){
                    q.push(cur->neighbors[i]); //BFS
                    seens.insert(cur->neighbors[i]);//记录已变量过的节点
                }
            }
        }
        return res;
    }
};
```