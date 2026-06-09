
```
class Solution {
public:
    map<int, bool> isLeaf;
    map<int, vector<int>> nodeMap;
    void getLeafMap(TreeNode* node)
    {
        if (!node) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            isLeaf[node->val] = true;
        } else {
            isLeaf[node->val] = false;
        }
        getLeafMap(node->left);
        getLeafMap(node->right);
    }

    void getNodeMap(TreeNode* father, TreeNode* node)
    {
        if (!node) {
            return;
        }
        if (father) {
            nodeMap[node->val].push_back(father->val);
        }
        if (node->left) {
            nodeMap[node->val].push_back(node->left->val);
        }
        if (node->right) {
            nodeMap[node->val].push_back(node->right->val);
        }
        getNodeMap(node, node->left);
        getNodeMap(node, node->right);
    }

    int findClosestLeaf(TreeNode* root, int k) {
        getLeafMap(root);
        getNodeMap(nullptr, root);
        if (isLeaf[k]) return k;
        queue<int> que;
        for (auto val : nodeMap[k]) {
            que.push(val);
        }
        while (!que.empty()) {
            int nodeVal = que.front(); que.pop();
            if (isLeaf[nodeVal]) return nodeVal;
            for (auto val : nodeMap[nodeVal]) {
                que.push(val);
            }
        }
        return -1;
    }
};
```
