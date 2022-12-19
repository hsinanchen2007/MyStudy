### 解题思路
执行用时 :156 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :63.1 MB, 在所有 C++ 提交中击败了100.00%的用户

此处撰写解题思路
一遍dfs 从低向上存储以各节点为根的子树的和。
vec.end()-1 中存储的就是整棵树的和sum。
遍历vec, (sum-vec[i])*vec[i]代表从以该节点为根的树砍掉获得的乘积。
需要注意的地方是(sum-vec[i])*vec[i]会超出，可以用long int临时存储。

### 代码

```cpp
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
class Solution {
public:
    vector<long int> vec;
    int dfs(TreeNode* root){
        // 获取以各节点为根的子树的和
        if(root==NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int temp = left+ right + root->val;
        vec.push_back(temp);
        return temp;
        
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        int len = vec.size();
        int sum = vec[len-1];
        long int res=0;
        long int temp;
        for(int i=0;i<len;i++){
            temp = (sum-vec[i])*vec[i];
            res = max(res,temp);
        }
        return res%(1000000000+7);
    }
};
```