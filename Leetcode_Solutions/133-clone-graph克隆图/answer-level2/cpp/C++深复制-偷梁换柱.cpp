### 解题思路
思路：
1.遍历图获得所有的节点及所带信息
2.在创建新的节点，值一样，但是地址不一样
3.创建新节点的边，仿照原来节点的边
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

    //第一步获取所有的节点，以及映射
    //自己创建节点，
    Node* cloneGraph(Node* node) {
       if (node == NULL) return NULL;
       map<int,Node*> map1;//原先每个标号的节点，对应的地址映射
       map<Node*,int>visit;//如果为0表示没有添加到映射中，1表示添加到映射中
       stack<Node*> stack1;//将要访问队列
       map<int,Node*> map2;//新的节点映射
       map1[node->val] = node;
       Node* p;
       stack1.push(node);
       while(!stack1.empty())
       {
           p = stack1.top();
           stack1.pop();
           visit[p] = 1;
        //遍历其相邻表
        for(int i=0;i<p->neighbors.size();i++)
        {
            if(visit[p->neighbors[i]] == 1) continue;
            else 
            {
                map1[p->neighbors[i]->val] = p->neighbors[i];
                //添加到访问队列中
                stack1.push(p->neighbors[i]);
            }
        }
       }
       //根据map1的节点值，建立新的节点
        map<int,Node*>::iterator it;
        for(it = map1.begin();it != map1.end();it++)
        {
            Node * l = new Node(it->first);
            map2[it->first] = l;
        }
         for(it = map1.begin();it != map1.end();it++)
         {
             for(int i=0;i<it->second->neighbors.size();i++)
             {
                 map2[it->first]->neighbors.push_back(map2[it->second->neighbors[i]->val]);
             }
         }
         return map2[node->val];
    }
};
```