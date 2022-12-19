### 解题思路
核心要点：设置两个双端队列deque，将root初始放在tq1，迭代处理tq1的所有元素，并将子节点全部存入tq2，同样方法再处理tq2
执行用时 :4 ms, 在所有 C++ 提交中击败了85.35%的用户
内存消耗 :12.4 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    vector<int> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>result;
        deque<TreeNode*>tq1(1,root);
        deque<TreeNode*>tq2;
        while(!tq1.empty()||!tq2.empty()){
            while(!tq1.empty()){
                result.push_back(tq1.front()->val);
                if(tq1.front()->left!=NULL){
                    tq2.push_back(tq1.front()->left);
                }
                if(tq1.front()->right!=NULL){
                    tq2.push_back(tq1.front()->right);
                }
                tq1.pop_front();
            }
            while(!tq2.empty()){
                result.push_back(tq2.front()->val);
                if(tq2.front()->left!=NULL){
                    tq1.push_back(tq2.front()->left);
                }
                if(tq2.front()->right!=NULL){
                    tq1.push_back(tq2.front()->right);
                }
                tq2.pop_front();
            }
        }
        return result;
    }
};
```