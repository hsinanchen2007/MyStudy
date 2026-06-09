BFS，N叉树和二叉树也没什么区别

代码：
```
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> node;
        if (root) {
            node.push(root);
            vector<int> temp(1, root->val);
            ans.push_back(temp);
        }
        while (!node.empty()) {
            int num = node.size();
            vector<int> temp;
            while (num) {
                for (int i = 0; i < node.front()->children.size(); i++) {
                    if (node.front()->children[i]) {
                        node.push(node.front()->children[i]);
                        temp.push_back(node.front()->children[i]->val);
                    }
                }
                node.pop();
                num--;
            }
            if(!node.empty())
                ans.push_back(temp);
        }
        return ans;
    }
};
```
