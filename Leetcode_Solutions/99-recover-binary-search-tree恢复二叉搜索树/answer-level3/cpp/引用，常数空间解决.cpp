### 解题思路
![4.png](https://pic.leetcode-cn.com/57b4d5e7a66e65fb873202176be47599365178df77ced354a8f231b146d4b6bf-4.png)
- 中序遍历二叉树，通过引用确定上一个节点（中序遍历时节点的值单调递增）。
- 如果上一个节点的值比该节点的值大，那么将2个节点都压入数组（不知道是不是“相邻”的两个节点交换），如果后面还有这种情况，那么将小的那个节点压入数组。
- 遍历完后看数组中有2个节点还是三个节点，如果2个则表示是“相邻”的节点交换，如果3个则不是。（不理解的话自己举几个样例看看）
- 将节点的值交换即可。
- （这里指的相邻是中序遍历的顺序相邻，即单调递增数组相邻的数）


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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>vec;
        TreeNode* pre=NULL;
        recoverTree(root,vec,pre);
        if(vec.size()==2){
            int temp=vec[0]->val;
            vec[0]->val=vec[1]->val;
            vec[1]->val=temp;
        }
        else{
            int temp=vec[0]->val;
            vec[0]->val=vec[2]->val;
            vec[2]->val=temp;
        }
    }
    void recoverTree(TreeNode* root,vector<TreeNode*>& vec,TreeNode*& pre){
        if(!root) return;
        recoverTree(root->left,vec,pre);
        if(pre&&vec.size()==0){
            if(root->val<pre->val){
                vec.push_back(pre);
                vec.push_back(root);
            }
        }
        else if(vec.size()==2&&(pre&&root->val<pre->val)) vec.push_back(root);
        pre=root;
        recoverTree(root->right,vec,pre);
    }
};
```
下面是用了O(N)的空间的方法，好理解一点
```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int>vec;
        recoverTree(root,vec);
        sort(vec.begin(),vec.end());
        recoverTree1(root,vec);
    }
    void recoverTree(TreeNode* root,vector<int>& vec){
        if(!root) return;
        recoverTree(root->left,vec);
        vec.push_back(root->val);
        recoverTree(root->right,vec);
    }
    void recoverTree1(TreeNode* root,vector<int>& vec){
        if(!root) return;
        recoverTree1(root->left,vec);
        root->val=vec[0];
        vec.erase(vec.begin());
        recoverTree1(root->right,vec);
    }
};
```
