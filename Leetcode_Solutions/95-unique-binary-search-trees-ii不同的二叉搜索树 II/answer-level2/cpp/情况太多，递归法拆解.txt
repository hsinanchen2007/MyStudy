### 解题思路
首先BST的左边到右边数字递增。参考很常见的一个思路，1到n依次作为root，root的左边和右边生成以同样的方法递归生成subTree。
值得注意的是：
1.用for循环遍历拼接subTree
2.如何拼接树
3.考虑n=0
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
    vector<TreeNode*> getSubTree(int a,int b) {
        vector<TreeNode*> ans;
        if(a>b){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=a;i<=b;i++){
            vector<TreeNode*> leftnodes=getSubTree(a,i-1);
            vector<TreeNode*> rightnodes=getSubTree(i+1,b);
            for(TreeNode* left:leftnodes){
                for(TreeNode* right:rightnodes){
                    TreeNode* leave=new TreeNode(i);
                    leave->left=left;
                    leave->right=right;
                    ans.push_back(leave);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n)
            return getSubTree(1,n);
        else
            return  vector<TreeNode*> {};
    }
};
```