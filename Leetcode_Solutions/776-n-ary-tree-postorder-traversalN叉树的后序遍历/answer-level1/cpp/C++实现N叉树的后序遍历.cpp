```
class Solution {
public:
    // 后序遍历，首先最简单的做法是 记住前序 翻转就实现 (直接利用 1.前序遍历 2.翻转) 
    // 后插入

    // 第一种：递归  
    vector<int> postorder1(Node* root) {
        vector<int> ve;
        if (!root) return ve;
        recursivePreorder(root, ve);
        return ve;
    }

    void recursivePreorder(Node *node, vector<int>& ve) {
        if (!node) return;

        for (int i=0; i < node->children.size(); i ++) {
            Node *n = node->children[i];
            if (n) recursivePreorder(n,ve);
        }
        ve.emplace_back(node->val);
    }

    // 第二种：迭代 
   vector<int> postorder(Node* root) {
        vector<int> ve;
        if (!root) return ve;

        stack<Node*> st;
        st.push(root);
        
        while (!st.empty()) {
            Node *node = st.top();
            st.pop();

            if (node) {
                ve.emplace_back(node->val);
                
                vector<Node*> chs = node->children;
                if (!chs.empty()) {
                    int size = chs.size();
                    for (int i =0; i< size; i++) {
                        Node *n =  chs[i];
                        if (n) st.push(n);
                    }
                }
            }
        }
    
        reverse(ve.begin(),ve.end());
        return ve;
    }
};
```
