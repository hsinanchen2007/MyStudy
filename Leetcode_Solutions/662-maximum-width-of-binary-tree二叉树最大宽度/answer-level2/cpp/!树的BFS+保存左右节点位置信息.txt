### 解题思路
执行用时击败78.99%；
思路：
用BFS找到每一层的节点，同时保存位置信息：左儿子为2n，右儿子为2n+1；
注意点：
需要使用unsigned long long,给运算腾出足够大的数值空间；
也可以考虑每一层的减去最左边的编号。

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
    int widthOfBinaryTree(TreeNode* root) {
        //用BFS找到每一层的节点，同时保存位置信息：左儿子为2n，右儿子为2n+1
        if (root==NULL) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        int len;
        int ans=0;
        while(!q.empty()){
            len=q.size();
            ans=max((int)(q.back().second-q.front().second+1), ans);
            while(len){
                TreeNode* now=q.front().first;
                unsigned long long pos=q.front().second;
                q.pop();
                if (now->left) q.push({now->left, pos * 2});
                if (now->right) q.push({now->right, pos * 2+1});
                len--;
            }
        }
        return ans;
       
    }
    
};
```