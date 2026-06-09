### 解题思路
此处撰写解题思路
一个静态整形变量judge_，一个非静态整形变量judge，出现x或者y时，judge与judge_都加1.当judge中为2时，
表明是同一个父节点的孩子，当judge不为2,judge_为2时，表明是同一层不同父亲的孩子，即堂兄弟。
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>tem;
        if(root==NULL)return false;
        tem.push(root);
        while(tem.size()!=0)
        {
            set<int>data;
            int size=tem.size();
            static int judge_=0;
            judge_=0;
            for(int i=0;i<size;i++)
            {
                int judge=0;
                TreeNode* tem_node=tem.front();
                if(tem_node!=NULL)
                {
                    TreeNode* left_node=tem_node->left;
                    TreeNode* right_node=tem_node->right;
                    if(left_node!=NULL)
                    {
                        if(left_node->val==x||left_node->val==y)
                        {
                           judge++;
                           judge_++;
                        }
                    }
                    if(right_node!=NULL)
                    {
                        if(right_node->val==x||right_node->val==y)
                        {
                            judge++;
                            judge_++;
                        }
                    }
                if(judge==2)
                return false;
                if(judge_==2)
                return true;
                tem.push(left_node);
                tem.push(right_node);
                }
                tem.pop();
            }
        }
        return false;
    }
};
```