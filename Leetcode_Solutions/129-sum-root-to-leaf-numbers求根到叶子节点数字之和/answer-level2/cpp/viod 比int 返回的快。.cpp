### 解题思路
两个都是用的深度优先遍历。
使用一个temp来记录每条从根到叶的路径的值。

第一种是返回int类型。

第二种是直接传引用。不用返回值。注意这里sum是引用。 temp不是。


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
    // 执行用时 :8 ms, 在所有 C++ 提交中击败了44.68% 的用户
    // 内存消耗 :12.4 MB, 在所有 C++ 提交中击败了40.40%的用户
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!root->left&&!root->right) return root->val;
        return sumNumbersCore(root, 0);
    }
    int sumNumbersCore(TreeNode* root, int temp){
        int res = 0;
        if(!root->left&&!root->right){//来到叶节点
            temp = temp*10 + root->val;
            return temp;
        }
        temp = temp*10+root->val;
        int left = 0, right = 0;
        if(root->left) 
            left = sumNumbersCore(root->left, temp);
        if(root->right) 
            right = sumNumbersCore(root->right, temp);
        res = left+right;
        return res;
    }

    // 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
    // 内存消耗 :12.4 MB, 在所有 C++ 提交中击败了52.53%的用户
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!root->left&&!root->right) return root->val;
        int sum = 0;
        // int temp = 0;
        sumNumbersCore(root, sum, 0);
        return sum;
    }

    void sumNumbersCore(TreeNode* root, int& sum , int temp){
        if(!root->left&&!root->right){
            temp = temp*10+root->val;
            sum += temp;
            return;
        }
        temp = temp*10+root->val;
        if(root->left) sumNumbersCore(root->left, sum, temp);
        if(root->right) sumNumbersCore(root->right, sum, temp);
    }
};
```