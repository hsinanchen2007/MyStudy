### 解题思路
1.bfs借助队列
2.根节点入队列，循环判断直到队列为空
3.一个节点出队的时候，如果有左右子节点，就把孩子节点入队列。

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
        vector<vector<int>> result;
        if(root == NULL)
        {
            return result;
        }
        //定义队列压入根节点
        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty())//当队列不为空
        {
            vector<int> oneLevel; //用于保存每行的节点值
            int size = q.size();  //得到当前队列中的元素个数，即这行的节点个数
            
            for(int i = 0;i < size;i++)
            {
                //拿到队列头部节点，并保存值
                TreeNode *node = q.front();
                q.pop();
                oneLevel.push_back(node->val);//将元素值保存下来

                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            //一行保存完毕，结果存入
            result.push_back(oneLevel);
        }
        return result;
    }
};
```