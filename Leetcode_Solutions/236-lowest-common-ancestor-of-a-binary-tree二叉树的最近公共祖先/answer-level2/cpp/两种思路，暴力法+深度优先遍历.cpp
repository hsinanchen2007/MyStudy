### 解题思路
思路一：暴力解法，用链表保存从根节点到目标节点的路径，执行两遍查找，然后对比两条路径，找出最后一个共同节点，这种方法直观，但是需要两趟遍历，耗时约40ms，效率太低。

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> lp, lq;

        if (!findNode(root, p, lp) || !findNode(root, q, lq)) {
            return NULL;
        }

        auto iter_p = lp.begin(), iter_q = lq.begin(), pre_p = iter_p, pre_q = iter_q;

        while (iter_p != lp.end() || iter_q != lq.end()) {
            pre_p = iter_p;
            pre_q = iter_q;
            iter_p++;
            iter_q++;

            if (*iter_p != *iter_q) {
                return *pre_p;
            }
        }

        if (iter_p == lp.end()) {
            return *pre_p;
        } else if (iter_q == lq.end()) {
            return *pre_q;
        }

        return root;
    }

private:
    bool findNode(TreeNode* root, TreeNode* p, list<TreeNode*>& lp) {
        TreeNode *node = root;

        if (node == NULL) {
            return false;
        } else if (node == p) {
            lp.push_front(node);
            return true;
        } else if (node->left == NULL && node->right == NULL) {
            return false;
        }

        if ((node->left && findNode(node->left, p, lp)) || (node->right && findNode(node->right, p, lp))) {
            lp.push_front(node);
            return true;
        }

        return false;
    }
};
```



思路二：只用一趟遍历同时查找两个节点，这里用深度优先遍历，定义返回值，如果找到p就返回1，找到q就返回2。如果返回值首次为3，说明在这个节点上同时找到p和q，把当前节点设为结果即可。执行效率提高一倍，耗时16ms，击败96.04%的用户。

![1.png](https://pic.leetcode-cn.com/eb29c59ff4149ec6f01d0de855ddfecfb1939746f1054baeed86f8ac97284126-1.png)


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = NULL;
        dfs(root, p, q, result);
        return result;
    }

private:
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &result) { //1-只找到p，2-只找到q，3-找到p和q
        TreeNode *node = root;
        int ret = 0, ret_left = 0, ret_right = 0;

        if (node == NULL) {
            return 0;
        } else if (node == p) {
            ret = 1;
        } else if (node == q) {
            ret = 2;
        } else if (node->left == NULL && node->right == NULL) {
            return 0;
        }

        ret_left = dfs(node->left, p, q, result);
        ret_right = dfs(node->right, p, q, result);

        ret = ret + ret_left + ret_right;
        if (ret == 3 && result == NULL) {
            result = node;
        }

        return ret;
    }
};
```