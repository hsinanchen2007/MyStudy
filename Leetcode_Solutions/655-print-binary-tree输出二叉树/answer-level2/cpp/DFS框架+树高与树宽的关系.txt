### 解题思路
1、DFS树，求得树高；
2、通过公式，W=2^H - 1，求得树宽；
3、利用树高树宽初始化矩阵，用“”填充；
4、用二分法+DFS，把每个元素放到矩阵里：
1）二分法需要保存该元素的左边界和右边界，中间值即为元素位置；
2）DFS需要保存元素的层号。

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
    vector<vector<string>> printTree(TreeNode* root) {
        //先做DFS，找出树的深度
        //再把一个个值放进去
        int height=getHeight(root);
        vector<vector<string>> re(height, vector<string>(int(pow(2,height)-1),""));//初试化矩阵
        if (root==NULL) return re;
        DFS(root, 0, int(pow(2,height)-2), 0, re);//从根节点开始DFS
        return re;
    }
    int getHeight(TreeNode* root){//DFS求树的高度
        if (root==NULL) return 0;
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
    void DFS(TreeNode* root, int left, int right, int layer, vector<vector<string>> &re){
        if (left > right) return;
        int mid=(left+right)/2;//中间值为元素的位置
        re[layer][mid]=to_string(root->val);
        if (root->left != NULL) DFS(root->left, left, mid-1, layer+1, re);//更改左右边界、层号，向下一层递归
        if (root->right != NULL)DFS(root->right, mid+1, right, layer+1, re);
        return;
    }
};
```