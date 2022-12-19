感觉应该是可以改进，用队列存储了很多东西，不过思路还是正确的。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Status {
        TreeNode *p;
        int left, right, mid;
        Status(TreeNode *pp, int ll, int rr, int mm) : p(pp), left(ll), right(rr), mid(mm) {}
    };
    int findMaxNum(const vector<int> &nums, const int &start, const int &end) {
        int t = start;
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] > nums[t]) t = i;
        }
        return t;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        queue<Status> tmp;
        int left, right, mid = findMaxNum(nums, 0, nums.size() - 1);
        int tm;
        TreeNode *root = new TreeNode(nums[mid]), *p;
        tmp.push(Status(root, 0, nums.size() - 1, mid));
        while (!tmp.empty()) {
            left = tmp.front().left;
            right = tmp.front().right;
            p = tmp.front().p;
            mid = tmp.front().mid;
            tmp.pop();
            if (mid - 1 >= left) {
                tm = findMaxNum(nums, left, mid - 1);
                p->left = new TreeNode(nums[tm]);
                tmp.push(Status(p->left, left, mid - 1, tm));
            }
            if (mid + 1 <= right) {
                tm = findMaxNum(nums, mid + 1, right);
                p->right = new TreeNode(nums[tm]);
                tmp.push(Status(p->right, mid + 1, right, tm));
            }
        }
        return root;
    }
};
```