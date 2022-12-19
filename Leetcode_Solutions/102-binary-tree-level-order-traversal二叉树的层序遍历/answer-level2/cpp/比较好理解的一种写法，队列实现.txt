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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > a;
        queue<TreeNode *>q;
        if(root){
           q.push(root); //把根节点放进队列
        }
        //队列里面装结点，再把每一层的结点的值装进vector,最后把每层的vector装进二维vector
        while(!q.empty()){
            vector<int> a_part;  //每走一轮都要更新一次
            int len = q.size();  //当前队列长度，也就是某一层的结点数
            for(int i = 0;i < len; i++){ 
                //这句话的意思就是遍历某一层的所有结点
                TreeNode *temp = q.front();
                q.pop();  //出队，让队列回归空队列
                a_part.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);  //注意先左再右
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            a.push_back(a_part);  //把一维放进二维
        }
        return a;
    }
};
```