### 解题思路
如果一颗二叉树是完全二叉树，那么从队列中的第一个null开始到队尾都是null，否则中间会有非null值的
自己画个图实验一下就知道了

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        TreeNode *cur;
        while(qu.front()!=NULL)//一直入栈直到碰到第一个null节点
        {   
                cur=qu.front();qu.pop();
                qu.push(cur->left);
                qu.push(cur->right);
        }
        while(!qu.empty())
        {   if(qu.front()!=NULL) return false;  //如果后边有一个不是null 说明不是完全二叉树
            qu.pop();
        }
        return true;
    }
};
```