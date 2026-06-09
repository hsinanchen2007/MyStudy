### 解题思路
C++
执行用时 :12 ms, 在所有 C++ 提交中击败了41.26% 的用户
内存消耗 :13 MB, 在所有 C++ 提交中击败了100.00%的用户

核心思想，用队列对二叉树进行层次遍历，将每一层的 val 数据先尾插存入临时的 tmp 数组，一层遍历结束后，再把 tmp 数组头插至目标数组即可。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL) return v;
        queue<TreeNode*> q;
        vector<int> tmp;
        q.push(root);
        // 层次遍历
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                if(q.front()->left != NULL)
                    q.push(q.front()->left);   //下一层结点入队
                if(q.front()->right != NULL)
                    q.push(q.front()->right);   //下一层结点入队
                tmp.push_back(q.front()->val);   //这一层结点 val 值依次尾插至临时数组
                q.pop();    //这一层结点出队
            }
            v.insert(v.begin(), tmp);   //一层遍历结束，将临时数组 tmp 头插存入目标数组，因为题目要求自底向上
            tmp.resize(0);   //清空临时数组，进行下一层遍历
        }
        return v;
    }
};
```