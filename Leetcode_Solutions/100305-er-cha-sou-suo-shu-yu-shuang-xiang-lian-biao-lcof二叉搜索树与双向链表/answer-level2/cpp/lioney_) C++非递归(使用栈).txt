```
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* head = nullptr, *pre = nullptr;
        stack<Node*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(!head)  // head只赋值一次
                head = root;
            if(pre) {
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            root = root->right;
        }
        // 此时的pre代表中序遍历的最后一个节点
        pre->right = head;
        head->left = pre;
        return head;
    }
};
```
