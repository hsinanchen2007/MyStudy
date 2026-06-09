![Screenshot from 2019-11-21 22-44-37.png](https://pic.leetcode-cn.com/3bcfbf5cd3839887e7cfa10889387e132e9e991cd55cd7d492e8f5e8ea44125e-Screenshot%20from%202019-11-21%2022-44-37.png)
```c++
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int maxDepth = 0;
        int currentDepth = 0;
        int previousDepth = INT_MAX;
        return dfs(root, maxDepth, currentDepth, previousDepth);
    }

    bool dfs(TreeNode* p, int &maxDepth, int &currentDepth, int &previousDepth){
        if(p == nullptr){
            if(currentDepth < maxDepth - 1){
                return false;
            }
            if(currentDepth > previousDepth){
                return false;
            }
            maxDepth = max(maxDepth, currentDepth);
            previousDepth = currentDepth;
            return true;
        }
        currentDepth++;
        if(dfs(p->left, maxDepth, currentDepth, previousDepth) == false){
            return false;
        }
        if(dfs(p->right, maxDepth, currentDepth, previousDepth) == false){
            return false;
        }
        currentDepth--;
        return true;
    }
};
```
