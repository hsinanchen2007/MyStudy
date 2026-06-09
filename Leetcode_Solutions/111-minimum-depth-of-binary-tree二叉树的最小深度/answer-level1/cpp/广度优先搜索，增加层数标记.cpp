### 解题思路
广度优先搜索遍历树，在每层结束时增加一个标识，当遇到叶子结点时输出层数。
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
    int minDepth(TreeNode* root) {
        int ans = 0;
        if(root == NULL)  //判断树是否为空
        return ans;
        queue<TreeNode*> treenodes;
        treenodes.push(root);  
        TreeNode* flag = new TreeNode(INT_MAX);  //每层结束的标识
        treenodes.push(flag);
        ans ++;  //层数加一
        while(!treenodes.empty())
        {
            TreeNode* now = treenodes.front();
            treenodes.pop();
            if(now -> val == INT_MAX)  //如果本层结束了，判断是否存在下一层，若存在继续遍历，若不存在直接结束循环
            {
                if(treenodes.empty())
                break;
                else
                {
                    treenodes.push(flag);
                    ans ++;
                }
            }
            else
            {
            if(now -> left == NULL && now -> right == NULL) break;  //节点没有左右节点，说明为叶子结点
            if(now -> left != NULL)
            treenodes.push(now -> left);
            if(now -> right != NULL)
            treenodes.push(now -> right);
            }
        }   
        return ans;
    }
};
```