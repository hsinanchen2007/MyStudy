### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了52.61%的用户
内存消耗 :56 MB, 在所有 C++ 提交中击败了5.19%的用户
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
    // 中序遍历得到结点指针序列
    void order(TreeNode* node, vector<TreeNode*>& values){
        if(node==NULL) return;
        order(node->left,values);
        values.push_back(node);
        order(node->right,values);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> values;
        order(root,values);
        // 找到一对结点i,j(i<j,values[i]->val > values[j]->val),说明这对结点可能是被交换的
        // 但还要满足将i,j交换后就成平衡二叉树=>   values[i]->val < values[j+1]->val (有一特殊情况，即j为最后一个结点)
        for(int i=0;i<values.size();i++){
            for(int j=i+1;j<values.size();j++){
                if(values[i]->val > values[j]->val && (j==values.size()-1 || values[i]->val < values[j+1]->val)){
                    int temp = values[i]->val;
                    values[i]->val = values[j]->val;
                    values[j]->val = temp;
                    break;
                }
            }
        }
    }
};
```