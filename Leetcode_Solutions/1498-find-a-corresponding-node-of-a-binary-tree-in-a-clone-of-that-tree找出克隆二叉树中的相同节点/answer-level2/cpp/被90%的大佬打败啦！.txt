想法很简单，层次遍历，同时进行，然后原树匹配成功的时候，另一棵树也就成功了，返回就行了。
（我猜效率低的原因可能是要匹配的节点的深度比较大，所以匹配成功的时候，已经检测了很多的节点。）
```
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<TreeNode *> sta1,sta2;
        TreeNode *p = NULL,*q = NULL;
        p = original;
        q = cloned;
        sta1.push_back(p);
        sta2.push_back(q);
        while(p != target&&sta1.size() > 0)
        {
            p = sta1[0];
            sta1.erase(sta1.begin());//取出来，再删除
            if( p->left)//入左节点
                sta1.push_back(p->left);
            if( p->right)//入右节点
                sta1.push_back(p->right);
            q = sta2[0];//克隆的与原来的是同样的操作
            sta2.erase(sta2.begin());
            if( q-> left)
                sta2.push_back(q->left);
            if( q->right)
                sta2.push_back(q->right);
        }
        return q;
    }
};*斜体*
```
