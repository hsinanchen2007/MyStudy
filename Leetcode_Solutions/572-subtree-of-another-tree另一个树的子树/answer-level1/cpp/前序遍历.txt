### 解题思路
对t进行前序遍历，每次用t子树和s树，进行比较，只有有一个t的子树和s相同，就表示true；

在进行t子树和s树进行对比的时候，需要每个节点 完全相同，才表示是相同的子树。这个类似于有一道题目，比较两个树，是否是相同的数。

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s){
            return false;
        }
        // if (s->val == t->val){ //前序遍历 -- 先找到一个节点的值等于t的根节点，然后再比较具体的每一个节点的值
        //     return  ||;
        // }
        return isSame(s,t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }


    bool isSame(TreeNode *s ,TreeNode *t){
        if(!s && !t){
            return true;
        }
        if(!s || !t){
            return false;
        }

        return (s->val == t->val) && isSame(s->left,t->left) && isSame(s->right, t->right);
    }

};
```