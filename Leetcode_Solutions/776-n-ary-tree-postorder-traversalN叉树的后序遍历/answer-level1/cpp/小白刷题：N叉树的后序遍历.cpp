与前序遍历类似，非递归需要借用栈，但栈的话很明显会先遍历根再遍历枝与叶

故而若想得到左->右->根的顺序，可以先类似前序按根->右->左遍历，然后将结果vector反转即可

代码：
```
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> s;
        if (root)
            s.push(root);
        while(!s.empty()) {
            Node* p = s.top();
            ans.push_back(p->val);
            s.pop();
            int len = p->children.size();
            for (int i = 0; i < len; i++) {
                if (p->children[i])
                    s.push(p->children[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
