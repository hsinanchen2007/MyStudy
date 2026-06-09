### 解题思路
首先要理解分裂，当一棵树分裂以后，**其中一个树(1树)的根节点为原本树的根节点，另一个树(2树)的根节点为断裂边的一端节点**。那么枚举每一根边断裂的情况，可以发现任何一个节点（除根节点）均可以作为2树的根节点。

所以题目就转化为遍历每一个子节点，计算以该节点为根节点的树子节点之和。最后**求(sum * (sum - count))的最大值**。

我们首先来看一个简单并易于理解的代码 **（超时）**：
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
    const int MOD = 1000000007;
    long long max = 0;
    int len;
    
    int getCount(TreeNode* root){
        if(root == NULL)    return 0;                                
        return root->val + getCount(root->left) + getCount(root->right);
    }
    //深度优先搜索计算以root为根节点的树各个子节点之和
    
    void f(TreeNode* root){
        if(root == NULL)    return ;
    
        int temp = getCount(root);
        long long ans = (long long)temp * (len - temp);
        if(ans > max)   max = ans;

        f(root -> left);
        f(root -> right);
    }
    //这一段代码很好理解，不看中间3句，就是一段先序遍历。
    
    int maxProduct(TreeNode* root) {
        len = getCount(root);
        f(root);
        return max%MOD;
    }
};
```
这一段代码，就是通过先序遍历每一个子节点，并通过getCount()函数计算每一个子树的节点和，但是这样会超时。至于为什么超时，我们可以分析，首先**在f()函数的递归中，会调用getCount进行又一次的递归。这样就会使复杂度升为(n^2)**。既然问题找到了，那么我们要怎么才可以避免掉getCount函数的使用呢？
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
    const int MOD = 1000000007;
    long long ans = 0;
    int len;
    
    int getCount(TreeNode* root){
        if(root == NULL)    return 0;                                           
        return root->val + getCount(root->left) + getCount(root->right);    
    }
    
    int f(TreeNode* root, int len){
        if(root == NULL)    return 0;
    
        int temp = root->val + f(root->left, len) + f(root->right, len);
        ans = max((long long)temp * (len - temp), ans);

        return temp;
    }
    
    int maxProduct(TreeNode* root) {
        len = getCount(root);
        f(root, len);
        return ans%MOD;
    }
};
```
改进后的代码主要在f()函数上。这里的先序遍历，改为了一句
```
int temp = root->val + f(root->left, len) + f(root->right, len);
```
并成为了后序遍历

可以看到f函数具有了返回值，这段代码和getCount非常像，**其返回值和getCount是一样的。**