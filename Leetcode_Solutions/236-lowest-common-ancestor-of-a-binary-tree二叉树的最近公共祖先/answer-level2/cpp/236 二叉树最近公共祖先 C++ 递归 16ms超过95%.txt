### 解题思路
![image.png](https://pic.leetcode-cn.com/752690089c66b922a614bff2a4390fc2326c8f9491d668d5b5242b431f4edc40-image.png)

递归思路
几种场景，
1.先搜索左子树
若搜索到了，那么直接返回。
若(get_q_local && root == p) || (get_p_local && root == q)
则res = root
2.在搜索右子树
思路同上，
3.最后更新搜索结果 get_p get_q
注意
1.需要考虑场景的互斥，即不可直接用get_q，而是用local_get_q
2.找到答案后立刻返回，保证 最近 公共祖先

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
    void findlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* & res, bool & get_p, bool & get_q) {
        if (!root) return;
        if (res) return;
        bool get_p_local = false, get_q_local = false;
        findlowestCommonAncestor(root->left, p, q, res, get_p_local, get_q_local);
        if (res) return;
        if (get_p_local && get_q_local) {
            res = root->left;
            return;
        }
        if ((get_q_local && root == p) || (get_p_local && root == q)) {
            res = root;
            return;            
        }
        if (get_p_local) get_p = true;
        if (get_q_local) get_q = true;
        get_p_local = false;
        get_q_local = false;
        findlowestCommonAncestor(root->right, p, q, res, get_p_local, get_q_local);
        if (res) return;
        if (get_p_local && get_q_local) {
            res = root->right;
            return;
        }
        if ((get_q_local && root == p) || (get_p_local && root == q)) {
            res = root;
            return;            
        }
        if (get_p_local) get_p = true;
        if (get_q_local) get_q = true;
        if (get_p && get_q) {
            res = root;
            return;
        }
        if (root == p) get_p = true;
        if (root == q) get_q = true;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        bool get_p = false;
        bool get_q = false;
        TreeNode* res = NULL;
        findlowestCommonAncestor(root, p, q, res, get_p, get_q);
        return res;
    }
};
```