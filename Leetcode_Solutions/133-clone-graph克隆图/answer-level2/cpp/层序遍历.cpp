### 解题思路
用一个map记录转换，层序遍历一次
### 代码

```cpp

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        map<Node*,Node*> m;
        queue<Node*> q;
        Node* n=new Node(node->val);
        m[node]=n;
        q.push(node);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                Node* temp=q.front();
                q.pop();
                //cout<<temp->val<<endl;
                vector<Node*> vtemp;
                for(auto a:temp->neighbors){
                    if(m.count(a)){
                        vtemp.push_back(m[a]);
                    }
                    else{
                        n=new Node(a->val);
                        m[a]=n;
                        vtemp.push_back(m[a]);
                        q.push(a);
                    }
                }
                m[temp]->neighbors=vtemp;
            }
        }
        return m[node];

    }
};
```