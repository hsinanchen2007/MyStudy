### 解题思路
和上题层次遍历的迭代思路一样，只不过在每层遍历的时候用双端队列，偶数层在后面加（从零层开始算），即从左往右，奇数层在前面加（从零层开始算），即从右往左。
直接看代码好了
![1.png](https://pic.leetcode-cn.com/446719feec0baae58e1c0fc7cfa1576e94f87900b35d564ad5f62f373fd8dd06-1.png)

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
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            deque<int> temp;  //双端队列
            for(int i = 0; i < n; i++){  // 一层
                TreeNode* p = q.front();
                q.pop();
                if(level % 2 == 0)
                    temp.push_back(p->val);  //偶数层在后面加（从零层开始算），即从左往右
                else
                    temp.push_front(p->val);  //奇数层在前面加（从零层开始算），即从右往左
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            res.push_back(vector<int>(temp.begin(), temp.end()));  //添加到结果中
            level++;
        }
        return res;
    }
};
```