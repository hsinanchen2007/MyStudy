### 解题思路
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
（一）递归
```
// class Solution {
// public:
// 	vector<int> inorderTraversal(TreeNode* root) {
// 		vector<int> res;
// 		inorder(root, res);
// 		return res;
// 	}
// 	void inorder(TreeNode *root, vector<int> &res) {
// 		if (!root) return;
// 		if (root->left) inorder(root->left, res);
// 		res.push_back(root->val);
// 		if (root->right) inorder(root->right, res);
// 	}
// };
```

（二）非递归

1. 前序遍历（栈）
```
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur||!st.empty()){
            while(cur){
                res.push_back(cur->val); //先根，再左，后右
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return res;
	}
};
```
2. 中序（栈）
### 代码

```cpp
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur||!st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val); //左 根 右
            cur = cur->right;
        }
        return res;
	}
};

```
3. 后序（栈）
```
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* last = NULL;
        while(cur||!st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
//当右子树弹出后遇到根结点又会将右子树结点压入栈中，造成死循环，因此我们需要在定义一个变量last代表最后一个访问的结点，当last与栈顶结点的右子树结点相同时，则不再将右子树结点压入栈中。
            if(cur->right&&last! = cur->right){
                cur = cur->right;
            }
            else if((NULL==cur->right)||(last==cur->right)){
                res.push_back(cur->val); //左 右  根
                last = cur;
                st.pop();
                cur = NULL;
            }
        }
        return res;
	}
};
```

4. 层序遍历（队列）
```
class Solution {
public:
    vector<int> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> Q;
        TreeNode* cur = root;
        Q.push(cur);
        int level = 0;
        while(!Q.empty()){
            for(int i = Q.size()-1;i>=0;--i){
                cur = Q.front();
                Q.pop();
                res.push_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
        }
    return res;
    }
};
```
