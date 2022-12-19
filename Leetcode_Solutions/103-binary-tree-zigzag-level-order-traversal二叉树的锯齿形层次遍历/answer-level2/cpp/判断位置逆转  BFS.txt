### 解题思路
此处撰写解题思路

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>res;
        if(root==NULL) return res;
        vector<int>part;
        TreeNode *temp;
        int sizeque;
        queue<TreeNode *>que;
        que.push(root);
        int level=1;
        while(!que.empty()){
            sizeque=que.size();     //注意：这里有个sizeque是每层队列的长度
            for(int i=0;i<sizeque;i++){       //循环的时候通过出队列遍历这层的每一个节点
                temp=que.front(); 
                que.pop();
                part.push_back(temp->val);
                if(temp->left!=NULL) que.push(temp->left); //左边有就添加左边的
                if(temp->right!=NULL) que.push(temp->right);//右边有就添加右边的
            }
            if(level%2==0)     //重点就是在偶位置哪里逆转一下
            reverse(part.rbegin(),part.rend());//reverse()的时间复杂度为O（n)
            res.push_back(part);     
            part.clear(); 
            level++;
        }
        return res;
    }
};
```