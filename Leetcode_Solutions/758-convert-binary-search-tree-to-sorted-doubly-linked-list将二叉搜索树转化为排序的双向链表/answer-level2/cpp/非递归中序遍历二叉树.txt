### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        stack<Node*> st;
        if(root==nullptr) return root;
        Node* p = root;
        Node* head = nullptr;
        Node* pre = nullptr;
        while(p||!st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            if(!st.empty()){
                p = st.top();
                st.pop();
                if(head==nullptr){
                    head = p;
                    pre = p;
                }
                else{
                    p->left = pre;
                    pre->right = p;
                    pre = p;
                }
                p = p->right;
            }
        }
        pre->right = head;
        head->left = pre;
        return head;
    }
};
```