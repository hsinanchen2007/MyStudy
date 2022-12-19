### 解题思路
层次遍历，可以在上一层就提前结束，不过题解有2分查找，会比较快
但是实现起来会稍微复杂，因为需要从顶点再走下来

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
    int countNodes(TreeNode* root) {
      if(!root) return 0;

      queue<TreeNode*> q;
      q.push(root);
      int cnt = 0;
      while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < q.size(); i++){
          TreeNode* tmp = q.front();
          q.pop();
          cnt++;
          if(tmp->left) q.push(tmp->left);
          if(tmp->right) q.push(tmp->right);

          if(tmp->right == NULL)
            return cnt + q.size();
        }

      }
      return cnt;
    }
};
```