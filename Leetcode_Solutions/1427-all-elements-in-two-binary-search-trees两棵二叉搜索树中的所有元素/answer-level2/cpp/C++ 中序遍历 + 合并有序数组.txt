### 解题思路
本题涉及三个知识点：
+ 二叉树搜索树的性质
+ 二叉树的中序遍历
+ 合并有序数组：参考 **[leetcode合并有序数组](https://leetcode-cn.com/problems/merge-sorted-array)**
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> A, B;
        inorder(root1, A);
        inorder(root2, B);
        // 合并两个有序数组
        vector<int> res(A.size()+B.size());
        for(int cur1 = 0, cur2 = 0, cur = 0; cur1<A.size() || cur2<B.size(); ++cur){
            if(cur1 >= A.size()){
                res[cur] = B[cur2++];
            }else if(cur2 >= B.size()){
                res[cur] = A[cur1++];
            }else if(A[cur1] <= B[cur2]){
                res[cur] = A[cur1++];
            }else{
                res[cur] = B[cur2++];
            }
        }
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& v){
        if(root){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
};
```