比较基础可以通过**直接递归**实现和或者通过**栈**来模拟递归实现。

前序遍历即访问顺序按照: $root -> left -> right$的顺序，直至访问到空结点。按照这个思路很容易写出递归实现。代码如下：
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
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        pre_travel(root);
        return ret;
    }
    void pre_travel(TreeNode* root)
    {
        if(root)//当前结点非空
        {
            ret.push_back(root->val);//访问根节点
            pre_travel(root->left);//递归左子树
            pre_travel(root->right);//递归右子树
        }
    }
};
```

当然还可以通过自己用**栈**来完成递归的功能。即我们访问根节点后，然后访问其左子树，当左子树遍历完成后，我们需要访问右子树，此时我们就需要拿到父节点的信息，通过父节点我们从而访问其右子树。这样整棵树完成遍历后，继续回退到上一层。直至当前子树访问完成，同时栈为空。
下面是代码实现：
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return vector<int>();//空树，直接返回
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode* p=root;//p指向当前访问结点
        while(p||!st.empty())
        {
            while(p){//若当前结点非空
                ret.push_back(p->val);//访问该结点
                st.push(p);//记录该结点到栈，后面回退
                p=p->left;//进入左子树访问
            }
            // while条件的设置，保证下面st非空
            //若p非空，那么一定会压入新元素，此时st非空。若p为空，则st一定非空
            //按先序的，此时父节点已经访问，通过它拿到右孩子后就可以移除
            p=st.top();st.pop();
            p=p->right;//进入右子树访问
        }
        return ret;
    }
};
```