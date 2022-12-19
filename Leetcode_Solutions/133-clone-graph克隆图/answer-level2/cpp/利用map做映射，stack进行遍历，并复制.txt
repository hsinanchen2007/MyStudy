```
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        vector<Node*> vt;
        Node* n1, *n2, *m1, *m2;
        if(node == NULL)
            return NULL;
        vt.push_back(node);
        while(!vt.empty())
        {
            n1 = vt.front();
            vt.erase(vt.begin());
            if(mp.count(n1) == 0)
            {
                n2 = new Node(n1->val, vector<Node*>());
                mp[n1] = n2;
            }
            else
            {
                n2 = mp[n1];
            }
            for(auto m1:n1->neighbors)
            {
                if(mp.count(m1) == 0)
                {
                    m2 = new Node(m1->val, vector<Node*>());
                    mp[m1] = m2;
                    vt.push_back(m1);
                }
                else
                {
                    m2 = mp[m1];
                }
                n2->neighbors.push_back(m2);
            }
        }
        return mp[node];
    }
};
```
