### 解题思路
本人资深小白，此题解题思路也是借鉴他人的，没啥可说的，就说一些最基础的理解吧。
1 题外话： 关于struct TreeNode{}的定义问题
(1) 本例中二叉树采用链表的存储结构
(2) c++的结构体定义与c有所区别，在本定义中直接使用TreeNode在结构体内定义，但是在c中必须使用struct TreeNode进行定义；
(3) 关于结构体初始化问题，本例中使用了类的思想，可以将 TreeNode(int x) : val(x), left(NULL), right(NULL) {}看成
是一个结构体构造函数，采用初始化列表的形式进行初始化。
2 首先我们定义一个返回类型为动态数组类型（vector<int>）的函数，入参为结构体指针（即二叉树结构体），
然后我们定义了一个栈结构（stack<TreeNode*> stk）（我也不知道应该怎么称呼），一个动态数组类型（vector<int>）（用于返回），一个结构体指针（TreeNode*）（用于遍历）
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* temp = root;
其实以上这些都好理解，关键是这个循环条件怎么想到： while((!stk.empty())||(temp!=NULL))，先放在一旁，考虑循环体内的流程。由于是前序遍历（跟-左-右），所以我们首先：
        ans.push_back(temp->val);
然后进行压栈操作：
        stk.push(temp);
接下来要对左子树进行操作：
        temp = temp->left;
由于一直遍历到“左”的极限，所以第一层while(temp!=NULL)循环可以理解，即一直进行入栈操作
当当前temp不再有左子树的时候，即temp->left == NULL, 第一层循环结束，此时temp=NULL，但栈顶（stk）存储的是temp的父结点，所以第一层循环结束，我们对temp重新赋值：
        temp = stk.top();
并将栈顶元素弹出（该元素已经进行了遍历），由于此时已经在叶子结点，所以开始遍历其“右”侧元素，
        temp = temp->right;
直至整个栈为空，就完成了先序遍历。
自己拿一个二叉树试一下就清楚了
个人理解是二叉树遍历与栈结构的一种深度契合。
哈哈，自己还要加强理解。
不喜勿喷

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* temp = root;
        while((!stk.empty())||(temp!=NULL))
        {
            while(temp!=NULL)
            {
                ans.push_back(temp->val);
                stk.push(temp);
                temp = temp->left;
            }
            temp = stk.top();
            stk.pop();
            temp = temp->right;

        }
        return ans;

    }
};
```