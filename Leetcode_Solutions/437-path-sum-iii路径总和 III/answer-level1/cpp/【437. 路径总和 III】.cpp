## 思路一：层次遍历+DFS
从头节点，按层次遍历每个节点，对于每个节点，再按深度遍历，寻找是否存在路径和等于目标值。
### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> qt;
        qt.push(root);
        int res = 0;
        while (!qt.empty()) {
            TreeNode *cur = qt.front();
            qt.pop();
            int curSum = 0;
            res += helper(cur, sum, curSum);
            if (cur->left != nullptr) {
                qt.push(cur->left);
            }
            if (cur->right != nullptr) {
                qt.push(cur->right);
            }
        }
        return res;     
    }
    int helper(TreeNode *root, int sum, int curSum) {
        int ans = 0;
        curSum += root->val;
        if (curSum == sum) {
            ++ans;
        }
        if (root->left != nullptr) {
            ans += helper(root->left, sum, curSum);
        }
        if (root->right != nullptr) {
            ans += helper(root->right, sum, curSum);
        }
        return ans;
    }
};
```

## 思路二：两次递归
### 代码
```
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }        
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);     
    }
    int helper(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
    }
};
```


