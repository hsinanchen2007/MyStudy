执行用时 :16 ms, 在所有 cpp 提交中击败了97.87%的用户
内存消耗 :20.3 MB, 在所有 cpp 提交中击败了100.00%的用户
```
class Solution {
private:
    void p(queue<Node*> &q1, queue<Node*> &q2){
        Node *node1 = q1.front(); q1.pop();
        if(node1->left )
            q2.push(node1->left);
        if(node1->right)
            q2.push(node1->right);
        while(!q1.empty()){
            Node *node2 = q1.front(); q1.pop();
            node1->next = node2;
            if(node2->left)
                q2.push(node2->left);
            if(node2->right)
                q2.push(node2->right);
            node1 = node2;
        }
        if(!q2.empty())
            p(q2, q1);
        return;
    }
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        else{
            Node *res = root;
            queue<Node*> q1, q2;
            q1.push(root);
            p(q1, q2);
            return res;
        }   
    }
};
```
