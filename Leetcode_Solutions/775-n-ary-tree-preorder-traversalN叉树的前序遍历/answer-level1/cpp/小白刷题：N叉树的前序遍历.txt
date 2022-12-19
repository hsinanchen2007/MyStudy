非递归，如果想保证左侧子树总是能先遍历到，那么就需要借用栈了

入栈时，需要将子结点从右至左入栈，保证左侧子结点先遍历到

代码：
```
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> s;
        if (root)
            s.push(root);
        while(!s.empty()) {
            Node* p = s.top();
            ans.push_back(p->val);
            s.pop();
            int len = p->children.size();
            for (int i = len - 1; i >= 0; i--) {
                if (p->children[i])
                    s.push(p->children[i]);
            }
        }
        return ans;
    }
};
```
