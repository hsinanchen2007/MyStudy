### 解题思路
执行用时击败33.88%
DFS框架思路：
在DFS的时候，保存祖父的值和父亲的值，并且进行子节点搜索的时候，把下一个节点的祖父设置为当前节点的父亲。

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
    int re=0;
    int sumEvenGrandparent(TreeNode* root) {
        if (root==NULL) return 0;
        DFS(root, 1, 1);//设根节点的祖父和父亲都是奇数
        return re;
    }
    void DFS(TreeNode* root, int grand, int father){
        if (root==NULL) return;
        if (grand % 2==0) re+=root->val; //祖父是偶数，加入结果
        DFS(root->left, father, root->val);//设置当前节点的父亲为下一个节点的祖父
        DFS(root->right, father, root->val);
        return;
    }
};
```