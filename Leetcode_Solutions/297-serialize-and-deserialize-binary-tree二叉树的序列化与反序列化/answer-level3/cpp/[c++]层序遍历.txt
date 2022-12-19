```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ans = "";
        ans += "[";

        deque<TreeNode *> nodes;
        if (root) {
            nodes.push_back(root);
        }
        bool isLastLevel = true;

        //层序遍历
        while (!nodes.empty()) {
            int length = nodes.size();
            string level = "";
            for (int i = 0; i < length; ++i) {
                TreeNode *temp = nodes.front();
                nodes.pop_front();
                if (!temp) {
                    level += "null,";
                } else {
                    
                    level += to_string(temp->val) + ",";
                    nodes.push_back(temp->left);
                    nodes.push_back(temp->right);
                    //判断下一层所有节点是否都是叶子节点，如果都是那么下一层就是树的最后一层。
                    if (isLastLevel) {
                        if (temp->right) {
                            isLastLevel = !(temp->right->left || temp->right->right);
                        }
                        if (temp->left) {
                            isLastLevel = !(temp->left->left || temp->left->right);
                        }

                    }
                }
            }

            //如果是最后一层，则去掉右侧空节点
            if (isLastLevel) {
                while (!nodes.back()) {
                    nodes.pop_back();
                }
            }

            ans += level;
        }

        //不是空树的话去掉最后一个逗号
        if (root) {
            ans.erase(ans.length() - 1, 1);
        }

        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {

        //去掉方括号
        data.erase(0, 1);
        data.erase(data.length() - 1, 1);

        //空树
        if (data.length() == 0) {
            return (TreeNode *) nullptr;
        }

        //至少一个节点，创建root
        queue<string> nodeStrs = components(data);
        TreeNode *root = new struct TreeNode(stoi(nodeStrs.front(), nullptr, 10));
        nodeStrs.pop();
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodeStrs.empty()) {

            TreeNode *parent = nodes.front();
            nodes.pop();

            //除了最后一层的非空节点，都应该有left和right
            string leftStr = nodeStrs.front();
            nodeStrs.pop();
            if (leftStr != "null") {
                TreeNode *left = new struct TreeNode(stoi(leftStr, nullptr, 10));
                nodes.push(left);
                parent->left = left;
            }
            if (!nodeStrs.empty()) {
                string rightStr = nodeStrs.front();
                nodeStrs.pop();
                if (rightStr != "null") {
                    TreeNode *right = new struct TreeNode(stoi(rightStr, nullptr, 10));
                    nodes.push(right);
                    parent->right = right;
                }
            }
        }

        return root;
    }

private:
    //简易版split
    queue<string> components(string str) {
        queue<string> ans;
        while (str.length() > 0) {
            int i = 0;
            while (i < str.length() && str[i] != ',') {
                i += 1;
            }
            ans.push(str.substr(0, i));
            str.erase(0, i + 1);
        }
        return ans;
    }
};
```
