# 解法一：
```C++ []
class Solution {
public:
    void dfs(TreeNode* root, bool& valid, long& min_val, long& max_val, int& count) {
        if (root == NULL) {
            valid = true;
            min_val = LONG_MAX;
            max_val = LONG_MIN;
            count = 0;
            return;
        }
        bool lvalid, rvalid;
        long lmin, rmin;
        long lmax, rmax;
        int lcount, rcount;
        dfs(root->left, lvalid, lmin, lmax, lcount);
        dfs(root->right, rvalid, rmin, rmax, rcount);
        min_val = min(lmin, min(rmin, (long)root->val));
        max_val = max(lmax, max(rmax, (long)root->val));
        if (lvalid && rvalid && root->val < rmin && root->val > lmax) {
            valid = true;
            count = lcount + rcount + 1;
        } else {
            valid = false;
            count = max(lcount, rcount);
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        bool valid;
        long min_val;
        long max_val;
        int count = 0;
        dfs(root, valid, min_val, max_val, count);
        return count;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6ede157eaaab654f3957adf32fa075c6c61af94aae1a127e8f8c1660a3f917d0-image.png)


# 解法二：

```C++ []
class Solution {
public:
    int childCount(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + childCount(root->left) + childCount(root->right);
    }
    int maxVal(TreeNode* root) {
        if (root == NULL) return INT_MIN;
        return max(root->val, max(maxVal(root->left), maxVal(root->right)));
    }
    int minVal(TreeNode* root) {
        if (root == NULL) return INT_MAX;
        return min(root->val, min(minVal(root->left), minVal(root->right)));
    }
    bool isBST(TreeNode* root) {
        if (root == NULL) return true;
        if (maxVal(root->left) >= root->val || !isBST(root->left)) return false;
        if (minVal(root->right) <= root->val || !isBST(root->right)) return false;
        return true;
    }
    int largestBSTSubtree(TreeNode* root) {
        if (root == NULL) return 0;
        if (isBST(root)) return childCount(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
```

![image.png](https://pic.leetcode-cn.com/2ea74aca251a2fcfe3e52b63af1c8bd3605686996695f3daaa6ea500865642d6-image.png)
