### 解题思路
核心要点：设置两个deque进行交替存取，定义全局变量layer记录打印二叉树的层数（即deque交替的次数）
执行用时 :4 ms, 在所有 C++ 提交中击败了87.92%的用户
内存消耗 :12.6 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    vector<vector<int>> levelOrder(TreeNode* root) {     
        if(root==NULL){
            return {};
        }
        vector<vector<int>>result;
        int layer=0;
        deque<TreeNode*>tq1(1,root);
        deque<TreeNode*>tq2;
        while(!tq1.empty()||!tq2.empty()){
            if(!tq1.empty())result.push_back(vector<int>());
            while(!tq1.empty()){
                result[layer].push_back(tq1.front()->val);
                if(tq1.front()->left!=NULL){
                    tq2.push_back(tq1.front()->left);
                }
                if(tq1.front()->right!=NULL){
                    tq2.push_back(tq1.front()->right);
                }
                tq1.pop_front();
            }
            layer++;
            if(!tq2.empty())result.push_back(vector<int>());
            while(!tq2.empty()){
                result[layer].push_back(tq2.front()->val);
                if(tq2.front()->left!=NULL){
                    tq1.push_back(tq2.front()->left);
                }
                if(tq2.front()->right!=NULL){
                    tq1.push_back(tq2.front()->right);
                }
                tq2.pop_front();
            }
            layer++;
        }
        return result;
    }
};
```