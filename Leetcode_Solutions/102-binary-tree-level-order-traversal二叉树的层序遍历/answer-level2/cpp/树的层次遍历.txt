### 解题思路
此处撰写解题思路
层次遍历是很方便的一种遍历方法.
只是要注意,随着层次的增加,队列可能会爆掉.
因为容量是随层次指数级增加的.
还有vector向量的运用
它是模板库分配的占用heap区中的空间.
题目中要注意对分层的检测方法.
vector运用:
[vector<int>用法](https://blog.csdn.net/qinyuehong/article/details/92837359)
[vector<vector<int>>用法](https://www.cnblogs.com/tyty-Somnuspoppy/p/9361821.html)
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
        vector<vector<int>> s;
        queue<TreeNode*> q;
        if(!root) return s;
        int loc=1,nex=0,layer=0;//本层和下一层的数量
        q.push(root);
        s.push_back(vector<int>());
        while(!q.empty())
        {
            if(loc==0){////递延到下一层..
                layer++; loc=nex; nex=0; s.push_back(vector<int>());
            }
            TreeNode* p=q.front(); 
            q.pop(); loc--;//当前层要减小以识别本层元素的边界.
            s[layer].push_back(p->val);
            if(p->left) q.push(p->left),nex++;
            if(p->right) q.push(p->right),nex++;
        }
        return s;
    }
};
```