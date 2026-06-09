执行用时 :24 ms, 在所有 cpp 提交中击败了97.63%的用户
内存消耗 :16.5 MB, 在所有 cpp 提交中击败了63.06%的用户

思路：
①用BFS遍历所有的节点，并建立所有节点的深拷贝，并把新节点与老节点通过map建立映射（此时新节点的邻居链表存在且为空）
（注意规避重复遍历老节点）
②建立新节点邻居链表的指针关系
```
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return node;
        map<Node*, Node*> h;
        vector<Node*> old;
        set<Node*> s;
        queue<Node*> q;
        q.push(node);
        vector<Node*> res;
        //第一步
        while(!q.empty()){
            for(int size = q.size(); size > 0; size--){
                Node *oldnode = q.front(); q.pop();
                if(s.count(oldnode))    continue;
                for(auto i : oldnode->neighbors)
                    q.push(i);
                s.insert(oldnode);
                vector<Node*> tempv;
                Node *newnode = new Node(oldnode->val, tempv);
                h[oldnode] = newnode;
                old.push_back(oldnode);
                res.push_back(newnode);
            }
        }
        //第二步
        for(auto i : old){
            Node *newnode = h[i];
            for(auto j : i->neighbors)
                newnode->neighbors.push_back(h[j]);
        }
        return h[node];
    }
};
```
