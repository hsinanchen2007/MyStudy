### 解题思路
![image.png](https://pic.leetcode-cn.com/fde25e230faf96f2c60f523189ed9f805a60d7115cd5e09c8ff64decf137bb78-image.png)


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
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        dfs(root, sum, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return count;
    }

    void dfs(TreeNode* node, int sum, int num) {
        if (node == NULL) {
            return;
        }
        num += node->val;
        if (sum == num) {
            count++;
        }
        dfs(node->left, sum, num);
        dfs(node->right, sum, num);
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/b9ed0cd87964624043afc0eceebf2f11270b170b9594538eacb89bcc3aaed110-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
