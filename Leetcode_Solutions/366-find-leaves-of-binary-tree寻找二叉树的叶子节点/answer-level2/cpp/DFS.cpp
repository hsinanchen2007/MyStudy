### 解题思路
就是常规的DFS，每次搜到底保存好叶子节点后要删除当前所有的叶子节点

### 代码

```cpp
class Solution {
public:
    void DFS(TreeNode* root, vector<int>& layerAns)
    {
        TreeNode* leftNode = root->left;
        if (leftNode != NULL) {
            if (leftNode->left == NULL &&
                leftNode->right == NULL) {//检查一下下一层是不是叶子结点
                layerAns.push_back(leftNode->val);
                delete leftNode;
                root->left = NULL;//这里要打断左右节点，否则会重复搜索。这也是为什么要隔层判断，如果已经到叶子节点了就不好往回找父节点了
            } else {
                DFS(leftNode, layerAns);//下一层不是叶子节点，可以继续往下搜
            }
        }

        TreeNode* rightNode = root->right;
        if (rightNode != NULL) {
            if (rightNode->left == NULL &&
                rightNode->right == NULL) {
                layerAns.push_back(rightNode->val);
                delete rightNode;
                root->right = NULL;
            } else {
                DFS(rightNode, layerAns);
            }
        }
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        std::ios::sync_with_stdio(false);
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
         
        while (root->right != NULL ||
                root->left != NULL) {
            vector<int> layerAns;//把每次底层的叶子节点结果暂存起来
            DFS(root, layerAns);//每次搜到底，保存完底层结果后要删除底层，否则下次又搜到同样的底了
            ans.push_back(layerAns);//保存每次底层的结果
        }
        ans.push_back({root->val});//只剩下根节点了，最后保存

        return move(ans);
    }
};
```