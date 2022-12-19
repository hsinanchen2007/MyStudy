### 解题思路
- 本题考查树的层次遍历，首先判断数是否为空
- 借组队列结构，首先将根节点root入队
- 

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
        vector<vector<int> > res;
        if(root == NULL)  return res;
       
        queue<TreeNode*> q;//定义队列，注意类型为TreeNode*
        q.push(root);//根节点入队

        while(!q.empty())//当队列不为空时
        {
            vector<int> tmp;
            int len = q.size();//由于要求逐层打印，因此用队列长度来保证
            for(int i = 0;i < len ;i++)
            {
                TreeNode *t = q.front();
                q.pop();//队首元素出队
                tmp.push_back(t->val);//出队元素关键值保存在数组中
                if(t->left)
                    q.push(t->left);//有左孩子，则左孩子结点入队列
                if(t->right)
                    q.push(t->right);//有右孩子，则右孩子结点入队列
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```