### 解题思路
![image.png](https://pic.leetcode-cn.com/1b56e3f6a7f69802b04309d8958842db06afa1f3cc8bc8ebbce15cf3b41afc3b-image.png)

    整体思路：
    不管最长路径是什么，他肯定有一个root节点，且root节点左边的路径长度是左边所有路径中的最大长度，右边的路径长度是右边所有路径中的最大长度。那么问题就转化为，对于树中的每个节点，假设最长路径是以此节点为root节点，那么分别求左边和右边的最长路径长度，并综合比较（root、左+root、右+root、左+右+root）中的最大值，则得到以此节点为root时的最大路径长度。遍历完所有的节点，取最大值，就是要求的最长路径的长度。
    对于左子树最长路径的长度：
    (1) 如果左边路径只有1个节点，那么最大路径长度就是这一个节点的值。
    (2) 如果不只1个节点，则分别取左子树的左右最大路径长度，取其中的最大值，假设为m。此最大值+左子树根节点的值，可能不是最大的，因为此最大值有可能为负数。所以要取（m + leftRoot->val, leftRoot->val）中的最大值。
    (3) 在此过程中，已经取到了左子树的左右节点的最大长度，则同时可以计算以此左子树的root节点为根节点时的最大路径长度。
    右子树同理。
### 代码

```c

int g_maxPath = 0;

int maxEdge(struct TreeNode *root)
{
    if (root->left == NULL && root->right == NULL) {
        g_maxPath = g_maxPath > root->val ? g_maxPath : root->val;
        return root->val;
    }

    int leftMax = root->val;
    int rightMax = root->val;
    if (root->left != NULL) {
        leftMax = maxEdge(root->left);
    }

    if (root->right != NULL) {
        rightMax = maxEdge(root->right);
    }

    int curMaxPath;
    int select;
    if (root->left != NULL && root->right != NULL) {
        select = leftMax > rightMax ? leftMax : rightMax;
        curMaxPath = leftMax + rightMax + root->val > root->val ? leftMax + rightMax + root->val : root->val;
        curMaxPath = leftMax + root->val > curMaxPath ? leftMax + root->val : curMaxPath;
        curMaxPath = rightMax + root->val > curMaxPath ? rightMax + root->val : curMaxPath;
    } else if (root->left != NULL) {
        select = leftMax;
        curMaxPath = leftMax + root->val > root->val ? leftMax + root->val : root->val;
    } else if (root->right != NULL) {
        select = rightMax;
        curMaxPath = rightMax + root->val > root->val ? rightMax + root->val : root->val;
    }

    g_maxPath = g_maxPath > curMaxPath ? g_maxPath : curMaxPath;

    return select + root->val > root->val ? select + root->val : root->val;
}


int maxPathSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }
    g_maxPath = root->val;

    int leftMax = root->val;
    int rightMax = root->val;
    if (root->left != NULL) {
        leftMax = maxEdge(root->left);
    } 

    if (root->right != NULL) {
        rightMax = maxEdge(root->right);
    }

    int curMaxPath;
    if (root->left != NULL && root->right != NULL) {
        curMaxPath = leftMax + rightMax + root->val > root->val ? leftMax + rightMax + root->val : root->val;
        curMaxPath = leftMax + root->val > curMaxPath ? leftMax + root->val : curMaxPath;
        curMaxPath = rightMax + root->val > curMaxPath ? rightMax + root->val : curMaxPath;
    } else if (root->left != NULL) {
        curMaxPath = leftMax + root->val > root->val ? leftMax + root->val : root->val;
    } else if (root->right != NULL) {
        curMaxPath = rightMax + root->val > root->val ? rightMax + root->val : root->val;
    }
    
    g_maxPath = g_maxPath > curMaxPath ? g_maxPath : curMaxPath;

    return g_maxPath;
}

```