```
class Solution {
public:
    // 第一种：递归  (这个和二叉树遍历一个道理，只是left right 用vector遍历下就行)
    vector<int> preorder1(Node* root) {
        vector<int> ve;
        if (!root) return ve;
        recursivePerorder(root, ve);
        return ve;
    }

    void recursivePerorder(Node* node, vector<int>& ve) {
        if (!node) return;
        
        ve.emplace_back(node->val);
        int size = node->children.size();
        for (int i=0; i<size; i++ ) {
            Node *n = node->children[i];
            if (n) {
                recursivePerorder(n,ve);
            }
        }
    }

    // 第二种:迭代
     vector<int> preorder(Node* root) {
        vector<int> ve;
        if (!root) return ve;
       
       stack<Node*> st;
       st.push(root);
       while(!st.empty()) {
           Node *node = st.top();
           st.pop();

            if (node) {
                ve.emplace_back(node->val);
            }else {
                continue;
            }

            if (!node->children.empty()) {
                int size = node->children.size();
                for (int i=size-1; i>=0; i--) { // 注意：这里要倒序 stack FIFO
                    Node *n = node->children[i];
                    if (n) st.push(n);
                }
            }
       }

        return ve;
    }
};
```
