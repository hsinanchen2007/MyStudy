### 解题思路
输入的原图以下称为**旧图**，拷贝出来的图以下称为**新图**。
**旧图**中的结点以下称为**旧结点**，**新图**中的结点以下称为**新结点**

第一遍遍历**旧图**，遍历时，对每个**结点**创建**对应**的**新结点**，使用用map<node*,node*>使旧结点与新结点一一对应，旧结点为key，新结点为value。
遍历完所有结点时，所有旧结点对应的新结点都已经被创建。

再遍历一遍**旧图**，遍历时，每次遍历到的结点，暂且称为**当前结点**，通过map找到当前结点对应的新结点,通过当前结点的neighbors成员找到当前结点所有的邻居结点，并通过map找到所有这些邻居结点对应的新结点，然后再把所有这些邻居结点对应的新结点添加到当前结点对应的新结点的neighbors成员中。可以用一句话概括。**令旧结点对应的新结点的邻居指向旧结点的邻居对应的新结点**。
遍历完所有结点时，结点的连接关系都已经被复制完毕。

~~~
oldNew[temp]->neighbors.push_back( oldNew[temp->neighbors[i]] );
~~~

### 代码

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldNew;
        set<Node*> visited;
        queue<Node*> q;
        Node * temp;

        //遍历旧结点、为每个旧结点创建对应的新结点
        temp=node;
        if(temp)q.push(temp);
        while(!q.empty()){ 
            temp = q.front();
            q.pop();
            oldNew[temp] = new Node(temp->val);
            visited.insert(temp);
            for(int i=0; i<temp->neighbors.size();i++)
                if(visited.find(temp->neighbors[i])==visited.end()){    
                    q.push(temp->neighbors[i]);
                    visited.insert(temp->neighbors[i]);
                }
        }

        //把旧结点间的连接关系拷贝到新结点
        visited.clear();
        temp=node;
        if(temp)q.push(temp);
        while(!q.empty()){ 
            temp = q.front();
            q.pop();
            for(int i=0; i<temp->neighbors.size();i++) //旧结点对应的新结点的邻居指向旧结点的邻居对应的新结点
                oldNew[temp]->neighbors.push_back( oldNew[temp->neighbors[i]] );
            visited.insert(temp);
            for(int i=0; i<(temp->neighbors).size();i++)
                if(visited.find((temp->neighbors)[i])==visited.end()){    
                    q.push(temp->neighbors[i]);
                    visited.insert(temp->neighbors[i]);
                }
        }
        return oldNew[node];
    } 
};
```