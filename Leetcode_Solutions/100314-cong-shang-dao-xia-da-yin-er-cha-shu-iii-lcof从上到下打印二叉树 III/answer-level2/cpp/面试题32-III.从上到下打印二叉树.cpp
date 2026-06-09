### 解题思路
核心要点：设置一个双端队列deque和一个栈stack，分别存储奇数层节点和偶数层节点，处理方式同上题
执行用时 :4 ms, 在所有 C++ 提交中击败了85.78%的用户
内存消耗 :12.7 MB, 在所有 C++ 提交中击败了100.00%的用户
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
        if(root==NULL)return {};
        deque<TreeNode*>tq(1,root);
        stack<TreeNode*>ts;
        vector<vector<int>>result;
        int level=0;
        while(!tq.empty()||!ts.empty()){
            if(!tq.empty())result.push_back(vector<int>());
            while(!tq.empty()){
                result[level].push_back(tq.front()->val);
                if(tq.front()->left!=NULL)ts.push(tq.front()->left);
                if(tq.front()->right!=NULL)ts.push(tq.front()->right);
                tq.pop_front();
            }
            level++;
            if(!ts.empty())result.push_back(vector<int>());
            while(!ts.empty()){
                result[level].push_back(ts.top()->val);
                if(ts.top()->right!=NULL)tq.push_front(ts.top()->right);
                if(ts.top()->left!=NULL)tq.push_front(ts.top()->left);
                ts.pop();            
            }
            level++;
        }
        return result;
    }
};
```