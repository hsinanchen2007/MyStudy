### 解题思路

PreOrder 遍历

### 代码

```cpp
class Solution {
private:
    vector<int> leftBound;
    vector<int> rightBound;
    vector<int> leaves;
public:
    enum NodeType { Root = 0, LeftBound = 1, RightBound = 2, Other = 4 };
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        dfs(root, 0);
        vector<int> res;

        res.insert(res.end(), leftBound.begin(), leftBound.end());
        res.insert(res.end(), leaves.begin(), leaves.end());
        res.insert(res.end(), rightBound.rbegin(), rightBound.rend());
        
        return res;
    }
    
    void dfs(TreeNode* root, int type) {
        if(!root)
            return;
        switch(type) {
            case Root:
            case LeftBound:
                leftBound.push_back(root->val);
                break;
            case RightBound:
                rightBound.push_back(root->val);
                break;
            case Other:
                if(!root->left && !root->right)
                    leaves.push_back(root->val);
        }
        
        dfs(root->left, lchildFlag(root, type));
        dfs(root->right, rchildFlag(root, type));
    }
    
    int lchildFlag(TreeNode *node, int type) {
        switch(type) {
            case Root:
            case LeftBound:
                return LeftBound;
            case RightBound:
                if(node->right == nullptr)
                    return RightBound;
        }
        return Other;
    }
    
    int rchildFlag(TreeNode *node, int type) {
        switch(type) {
            case Root:
            case RightBound:
                return RightBound;
            case LeftBound:
                if(node->left == nullptr)
                    return LeftBound;
        }
        return Other;
    }
};
```