![leetcode.PNG](https://pic.leetcode-cn.com/91b6429f23c2d11d378d76b724b4edeba80ded835435702bb3dd0647a08ea818-leetcode.PNG)

```
书写递归函数的核心：
    一、递归的应用场景：子问题需与原问题为同样或类似的事，且规模更小（往往体现在函数参数的变化）

    二、如何思考递归调用：以栈的角度看待递归，函数递归调用是push（进栈），遇到return或者递归结束条件是pop（出栈）

    三、理解递归函数的返回：递归函数满足递归结束条件后可以返回栈顶元素(亦可以不返回任何东西)，接着当前栈顶元素pop(出栈）
    
    四、记住显式return或隐式return（满足递归结束条件后自动return）都会弹出栈顶元素
    
    五、书写递归函数的注意事项
    
        1、想清楚递归函数结束的条件
        2、如何处理不满足递归条件的情况
        3、递归函数参数如何变化
        4、递归返回值的处理
```
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;  // 之所以递归结束条件是这个，因为想到整棵树只有一个空的根节点
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        //if(left) cout<<left->val<<endl;
        //if(right) cout<<right->val<<endl;
        root->left = right;
        root->right = left;
        return root;
    }
};
```