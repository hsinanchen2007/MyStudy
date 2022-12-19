### 解题思路
1. 层次遍历每一个节点。
2. 以当前节点开始，路径上和为sum的数量。
### 代码

```cpp
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
    int pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> q;
        int res = 0, cur_sum = 0, cur_num = 0;

        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front(); q.pop();
//            cout << temp->val << ":\t";
            Sum(temp, sum, cur_sum, cur_num); res += cur_num;
//            cout << "#\t" << cur_num << endl;
            cur_num = 0;

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        return res;
    }

    void Sum(TreeNode *root, int sum, int cur_sum, int &cur_num) {
        if (root == nullptr) {
            return;
        }

        cur_sum += root->val;
//        cout << cur_sum << " ";
        if (cur_sum == sum){
            cur_num += 1;
        }

        Sum(root->left, sum, cur_sum, cur_num);
        Sum(root->right, sum, cur_sum, cur_num);
    }
};
```