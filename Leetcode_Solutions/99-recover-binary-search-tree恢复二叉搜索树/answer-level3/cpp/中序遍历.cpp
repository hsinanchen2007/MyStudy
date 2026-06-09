BST的中序遍历是从小到大的，那么如果违法了规律，必然说明这两个点其中之一或两者都是要交换的点。


所以就存储prev节点表示现在遍历的节点的前一个，然后进行比较，我用了mis1和mis2存储两个错误的节点，也就是需要交换的节点


我原先是存储在数组中（总共存四个），进行排序后找出两个顺序不同的，再交换这两个节点的val域，后来发现，必然是前面大的点和后面小的点进行交换。


反着思考的话，如果前面的点是小的点，后面的点是大的点，但是却不符合BST的定义，那么要交换的节点显然会不止2个。


所以用mis1存prev（大的点），mis2存p（小的点）（小的点在后续可能会更新）。


代码也是学习了别的大佬的，就是说个思路。


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
private:
    TreeNode *prev;
    TreeNode *mis1;
    TreeNode *mis2;
    
public:
    void dfs(TreeNode *p) {
        if (!p) return;
        dfs(p->left);
        if (prev && prev->val > p->val) {
            if (!mis1) mis1 = prev;
            mis2 = p;
        }
        prev = p;
        dfs(p->right);
        return;
    }
    
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        mis1 = nullptr;
        mis2 = nullptr;
        dfs(root);
        swap(mis1->val, mis2->val);
        return;
    }
};
```

这是我原先的代码，复杂度肯定是符合要求的，因为vector里也就最多4个值，要么2个值，但是显然不如上一种清晰。


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
private:
    TreeNode *prev;
    vector<TreeNode *> tmp;
    
public:
    void dfs(TreeNode *p) {
        if (!p) return;
        dfs(p->left);
        if (prev && prev->val > p->val) {
            tmp.push_back(prev);
            tmp.push_back(p);
        }
        prev = p;
        dfs(p->right);
        return;
    }
    
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        dfs(root);
        vector<TreeNode *> a(tmp);
        sort(a.begin(), a.end(), [](TreeNode *f, TreeNode *s) ->bool { return f->val < s->val; });
        int point;
        bool flag = 1;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] != a[i]) {
                if (flag) {
                    point = i;
                    flag = 0;
                } else {
                    swap(tmp[point]->val, tmp[i]->val);
                    return;
                }
            }
            
        }
        return;
    }
};
```
