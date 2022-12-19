![image.png](https://pic.leetcode-cn.com/57699aa831f3d71e1ee86cfd04edb6bdb5b02309db81614d342d1a4b5c876ff5-image.png)


### 解题思路
BFS遍历原先的图，队列q保存遍历的结点顺序
用字典mp保存是否建立对应结点是否创建新内存
用集合visit保存是否进过队列，防止重复遍历

这是我用C++写的第一个 中等难度的题目，纪念一下，看了其他CPP，觉得自己写的太稚嫩了
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
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        queue<Node *> q;//新建一个队列
        set<Node *> visit;//集合中的结点进出过队列

        q.push(node);//将第一个结点压入队列
        visit.insert(node);//第一个结点进过队列，就立刻进集合

        map<Node *,Node *> mp;//新老结点地址的对照
        
        Node* result;//返回的结点地址
        int flag=0;//用来标记是否是返回的结点地址

//接下来是典型的BFS
        while(!empty(q)){//队列不为空的时候
            
            Node *front=q.front();//取出队首
            Node *n;


            if(mp.find(front)==mp.end()){//对应的新结点还未分配内存
                n=new Node();//建立新结点
                mp.insert(make_pair(front,n));//新老对照入字典
                n->val=front->val;//对应的值填入
                if(!flag){
                    result=n;flag=1;
                }
            }else//建立过该节点，直接找到对应的新节点的内存
                n=mp.find(front)->second;
            

    //这里要对当前结点的vector邻接表做遍历
           vector<Node*>::iterator it=front->neighbors.begin();//遍历当前节点的邻接表
            
            Node *temp;                
            while(it!=front->neighbors.end()){//遍历当前节点的邻接表
                if(mp.find(*it)==mp.end()){    //如果遍历到的邻接点还未分配内存
                    temp=new Node();
                    temp->val=(*it)->val;
                    mp.insert(make_pair(*it,temp));
                    n->neighbors.push_back(temp);
                  //  visit.insert(*(it));//第一个结点进过队列
                }else//如果已经分配过内存
                    n->neighbors.push_back(mp.find(*it)->second);
       
                if(visit.find(*it)==visit.end()){//如果当前邻接点还未进队列，要入队
                    q.push(*it);
                    visit.insert(*it);
                }
                    

                it++;
                }

            q.pop();//出队
        }
        
    return result;

    }
};
```