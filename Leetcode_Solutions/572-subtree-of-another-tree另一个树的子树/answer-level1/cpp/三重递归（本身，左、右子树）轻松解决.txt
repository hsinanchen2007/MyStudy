### 解题思路
思路在注解里：
主要思路其实就是要么本身是t，要么左右子树是t,中间是或的关系

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
        if(s == NULL) return false;
  //要么本身是t，要么左右子树是t,中间是或的关系
        return (Judge(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t));
    }

    bool Judge(TreeNode* s, TreeNode* t){
//如果同时为空，就返回，这个要放在前面判断，不然后面访问可能会违法
       if(s == NULL && t == NULL) return true;
       //如果其中一个为空，就说明结构不一样
       if(s == NULL || t == NULL) return false;
       //如果值不同，结构也不一样
       if(s->val != t->val) return false;
       //经过判断筛选后，唯一的情况就是值一样
       //此时仍需要访问该节点的左右子树，是且的关系，因为左右子树必须完全一样
       return (Judge(s->left,t->left) && Judge(s->right,t->right));
    }
};
```