### 解题思路
此处撰写解题思路

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;      //用来存放结果
        TreeNode* T = root;
        TreeNode* pre = NULL;   //用来记录最近一个访问的节点
        stack<TreeNode*> s ;
        while(T||!s.empty()){   
            while(T){
                s.push(T);
                T = T->left;
            }
            T = s.top();
            if(T->right&&T->right!=pre)   //当栈顶元素的右孩子存在且没被访问时执行
                T = T->right;
            else{                          //当栈顶元素的右孩子不存在或右孩子已经被访问过时执行
                s.pop();                    //弹出栈顶节点
                ret.push_back(T->val);      //结果保存
                pre = T;                    //记录访问过的节点
                T = NULL;                   //初始化T为NULL,防止新的循环又使栈顶元素的左孩子进栈，即刚访问完的节点
            }
        }
    return ret;
    }
};
```

不知道是否道友们发现到此为止都没有把左孩子纳入条件？原因就是对于栈顶元素，它的左孩子一定是不存在或者已经被访问过的，所以我们根本不用管它，至于为什么，想不出来的可以画个图推演一下。

主要思路都在注释上面了，大伙自行理解哈，感觉这样写简洁很多。