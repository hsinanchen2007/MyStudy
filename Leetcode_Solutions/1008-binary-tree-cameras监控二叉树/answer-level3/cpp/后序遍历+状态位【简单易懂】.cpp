### 解题思路
    // 0-该节点放置了一颗色相头
    // 1-该节点可以被其他色相头看到
    // 2-该节点没有色相头关心她
    // 叶子节点始终默认不会放置色相头，也没人看得见她
    // 左子节点/右子节点如果只有1个可以被看到，则当前节点检测不到
    // 左右子节点都可以被看到，当前节点也看不到
    // 左右子节点有一颗检查不到时，放置一颗色相头
    // 递归走后序遍历，先访问左右子节点，再访问根节点

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
    int minCameraCover(TreeNode* root) {
        //特殊情况处理
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        //对root根节点做处理
        if (dfs(root) == 2) {
            count ++;
        }
        return count;
    }
    
    // 0-该节点放置了一颗色相头
    // 1-该节点可以被其他色相头看到
    // 2-该节点没有色相头关心她
    // 叶子节点始终默认不会放置色相头，也没人看得见她
    // 左子节点/右子节点如果只有1个可以被看到，则当前节点检测不到
    // 左右子节点都可以被看到，当前节点也看不到
    // 左右子节点有一颗检查不到时，放置一颗色相头
    // 递归走后序遍历，先访问左右子节点，再访问根节点
    int dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 2;  // 叶子节点始终无法被检视到
        }
        int left = -1;
        if (root->left != nullptr) {
            left = dfs(root->left);  // 求左节点值
        }
        int right = -1;
        if (root->right != nullptr) {
            right = dfs(root->right); // 求右节点值
        }
        if (left == 2 || right == 2) { // 左右子树有一个检查不到时，放置一颗色像头
            count ++; //计数器 + 1
            return 0;  // 放一颗色相头
        }
        if ((left == 1 && right == 1) || (left == 1 && right == -1) || (left == -1 && right == 1)) {  //左右子树出现了至少1个被监视到的，当前节点无法被监视到
            return 2;  
        } else if (left == 0 || right == 0) {  //左右子节点有一个是色相头，那就返回可以被检测到。
            return 1;
        }
        count ++;
        return 0; //默认放置一颗色相头,这里主要是只有左子树/右子树，且 == 2,那么就放置1颗色相头
    }
};
```