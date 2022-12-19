使用队列，并记录每一层入队的数和出队数，当本层的全部出队则证明本次已经遍历完成
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }
    queue<TreeNode *> que;
    que.push(root);
    int curLevel = 1;
    int nextLevel = 0;
    vector<int> value;
    while (!que.empty()) {
        TreeNode *temp = que.front();
        que.pop();
        curLevel--;
        value.push_back(temp->val);

        if (temp->left != nullptr) {
            que.push(temp->left);
            nextLevel++;
        }
        if (temp->right != nullptr) {
            que.push(temp->right);
            nextLevel++;
        }

        if (curLevel == 0) {
            curLevel = nextLevel;
            nextLevel = 0;
            ret.push_back(value);
            value.clear();
        }
    }
    return ret;
}