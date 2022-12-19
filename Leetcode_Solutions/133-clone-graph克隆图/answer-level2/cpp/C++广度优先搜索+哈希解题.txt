由于100个结点不算很多，开始直接创造100个结点出来，并且绑定哈希。
然后进行BFS，并且绑定相邻关系。
```
bitset<101> flag;
    unordered_map<int,Node*> hash;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        for(int i=1;i<101;i++)
        {
            Node* pNode=new Node(i);
            hash[i]=pNode;
        }
        flag.reset();
        queue<Node*> q;
        q.push(node);
        flag[node->val]=1;
        while(!q.empty())
        {
            Node* curp=q.front();
            int cur=curp->val;
            for(int i=0;i<curp->neighbors.size();i++)
            {
                hash[cur]->neighbors.push_back(hash[curp->neighbors[i]->val]);
                if(flag[curp->neighbors[i]->val]==0)
                {
                    flag[curp->neighbors[i]->val]=1;
                    q.push(curp->neighbors[i]);
                }
            }
            q.pop();
        }
        return hash[node->val];
    }
```
