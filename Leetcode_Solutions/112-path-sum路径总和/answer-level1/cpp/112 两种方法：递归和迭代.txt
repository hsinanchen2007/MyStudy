### 代码
```cpp []
//方法一：递归
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr)
            return false;
        sum = sum-root->val;
        if (root->left==nullptr && root->right==nullptr)
            return sum==0;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
```
```cpp []
//方法二：迭代
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr)
            return false;
        
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        stack<int> sumStack;
        sumStack.push(sum);
        TreeNode *currNode;
        while (!nodeStack.empty()) {
            currNode = nodeStack.top();
            nodeStack.pop();
            sum = sumStack.top();
            sumStack.pop();
            sum = sum-currNode->val;
            if (!currNode->left && !currNode->right && sum==0)
                return true;
            if (currNode->right) {
                nodeStack.push(currNode->right);
                sumStack.push(sum);
            }
            if (currNode->left) {
                nodeStack.push(currNode->left);
                sumStack.push(sum);
            }
                
        }

        return false;
    }
};
```