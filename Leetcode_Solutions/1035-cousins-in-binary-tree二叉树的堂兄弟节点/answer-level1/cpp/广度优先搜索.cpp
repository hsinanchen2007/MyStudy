### 解题思路
初始化nowlevel为-1，nowNode为NULL，使用广度优先搜索，当前节点的左节点的值等于x或y时，若此时nowlevel为-1，更新nowlevel和nowNode；若nowlevel不为-1，比较当前节点的level和nowlevel是否相等，当前节点和nowNode是否相等，若层数相等且父节点不同，为堂兄弟节点。
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
        bool ans = false;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 0, nowlevel = -1;  //存储题目要求节点的父节点的层数
        TreeNode* nowNode = NULL;  //存储题目要求节点的父节点
        while(!nodes.empty())
        {
            int num = nodes.size();  //便于层次遍历
            while(num -- > 0)
            {
                TreeNode* nownode = nodes.front();
                nodes.pop();
                if(nownode -> left)  //若当前节点的左子树存在
                {
                    //若当前节点的左节点的值等于x或y
                    if(nownode -> left -> val == x || nownode -> left -> val == y)
                    {
                        if(nowlevel == -1)  //nowlevel为-1，说明此节点是符合要求的第一个节点
                        {
                            nowlevel = level;  //更新nowle和nowNode
                            nowNode = nownode; 
                        }
                        else
                        {
                            //层数相等但父节点不相等，为true
                            ans = (nowlevel == level && nowNode != nownode) ? true : false;
                            break;
                        }
                    }
                    nodes.push(nownode -> left);
                }
                if(nownode -> right)  //同理判断当前节点的右子树
                {
                    if(nownode -> right -> val == x || nownode -> right -> val == y)
                    {
                        if(nowlevel == -1)
                        {
                            nowlevel = level;
                            nowNode = nownode;
                        }
                        else
                        {
                            ans = (nowlevel == level && nowNode != nownode) ? true : false;
                            break;
                        }
                    }
                    nodes.push(nownode -> right);
                }
            }
            level ++;
        }
        return ans;
    }
};
```