### 解题思路
- 核心要点：递归遍历二叉树，先右子树，再根，再左子树，设置全局变量count记录遍历到第k个节点就可以返回了
- 执行用时 :52 ms, 在所有 C++ 提交中击败了6.18%的用户
- 内存消耗 :24.1 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    int kthLargest(TreeNode* root, int k) {
        int count=0;
        int result;
        recur(root,count,k,result);
        return result;
    }
    void recur(TreeNode*root,int&count,int&k,int&result){
        if(root!=NULL){
            recur(root->right,count,k,result);
            if(count==k-1){
                result=root->val;
                count++;
            }
            else if(count<k-1){
                count++;
            }
            else return;
            recur(root->left,count,k,result);
        }
    }
};
```