### 解题思路
使用广度优先搜索，计算每一层节点的和，最后输出最后一层节点的和即可
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
    vector<int> ans;  //存储每层节点和的数组
    void BFS(TreeNode* root)
    {
        queue<TreeNode*> nodes;
        nodes.push(root);
        int sum = 0;
        while(!nodes.empty())
        {
            int nums = nodes.size();  //计算每一层有多少节点
            while(nums -- > 0)
            {
                TreeNode* nownode = nodes.front();
                nodes.pop();
                sum += nownode -> val;
                if(nownode -> left != NULL) nodes.push(nownode -> left);
                if(nownode -> right != NULL) nodes.push(nownode -> right);
            }
            ans.push_back(sum);  //将每层节点的保存
            sum = 0;
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)
        return 0;
        BFS(root);
        return ans[ans.size() - 1];
    }
};
```