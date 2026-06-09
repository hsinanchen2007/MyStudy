### 解题思路
广度优先搜索

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
        vector<vector<int>> res;//存储返回结果
        if(!root){
            return 0;
        }
        queue<TreeNode*> Q;//定义一个队列，先进先出
        TreeNode* p;
        Q.push(root);
        while(Q.empty()==0){
            vector<int> a;
            int width=Q.size();//获取当前队列的长度
            //将该层的值添加到数组，并将该层结点的左右指针入队列
            for(int i=0;i<width;i++){
                p=Q.front();//取出队列的第一个数据
                a.push_back(p->val);
                Q.pop();//先进先出，弹出已经存到数组的数据
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
                if(!p->left && !p->right) return res.size()+1;//若发现叶子结点，直接返回res的个数+1
            }
            res.push_back(a);
        }
    return res.size();

    }
};
```