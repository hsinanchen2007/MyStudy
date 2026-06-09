### 解题思路
层次遍历统计深度，遇到第一个叶子就返回深度。

### 代码

```cpp

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        TreeNode *p, *lastNode = root, *newLastNode = NULL;

        while(!q.empty()){
            p = q.front();
            q.pop();
            if(!p->left && !p->right){
                return depth + 1;
            }
            if(p->left){
                q.push(p->left);
                newLastNode = p->left;
            }
            if(p->right){
                q.push(p->right);
                newLastNode = p->right;
            }
            if(p == lastNode){
                depth++;
                lastNode = newLastNode;
            }
        }
        return depth;
    }
};
```