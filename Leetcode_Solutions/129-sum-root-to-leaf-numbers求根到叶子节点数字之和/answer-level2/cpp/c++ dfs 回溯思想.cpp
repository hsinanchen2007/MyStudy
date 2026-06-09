### 解题思路
与#257思路类似，套用先序遍历框架，将焦点移到对当前结点的操作和对传入参数的设置，剩下的交给递归。
1. 判断当前结点是否为叶子结点。如果是，显然意味着一趟路径已然完成，将这一趟的路径和传给总数和`sum`。之后`return`回上一层(叶子结点的父结点)，换路继续递归找出其与路径和(有回溯的思想在其中)。
2. 既然有回溯的思想，那显然会出现状态重置的部分。而且根据本题题意，需要设置暂时存储的变量用于存储每一条路径和。对于该问题，可以通过添加辅助函数，扩展一个参数`cur`，用于暂时存储每一条路径和，然后在其传入参数的赋值部分，由于一开始就赋上当前结点的值，因此后面递归的赋值也要赋上左右子节点的值。**注意**：递归蕴含着栈的思想，每个结点，只有当与它相关的左右子树全部遍历完成才会返回它的父结点，也就是说返回之前它自己的`cur`是一直存在的。


### 乘10自增，执行用时：4ms

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return sum;
        
        helper(root, root->val);   //提前赋值，后面递归的赋值也要相应改变
        return sum;
    }

    void helper(TreeNode* root, int cur){      //cur表示每一条路径和
        if(!root)
            return;
        
        if(!root->left && !root->right){
            sum += cur;
            return;
        }

        if(root->left)
            helper(root->left, cur * 10 + root->left->val);
        if(root->right)
            helper(root->right, cur * 10 + root->right->val);
        
        return;
    }

private:
    int sum = 0;    //记录所有和
};
```

<br/>
### 字符串转int，执行用时：8ms
```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return sum;
        
        helper(root, to_string(root->val));
        return sum;
    }

    void helper(TreeNode* root, string cur){
        if(!root)
            return;
        
        if(!root->left && !root->right){
            //字符串转int
            stringstream ss;
            int curNum;
            ss << cur;
            ss >> curNum;

            sum += curNum;
            return;
        }

        if(root->left)
            helper(root->left, cur + to_string(root->left->val));
        if(root->right)
            helper(root->right, cur + to_string(root->right->val));
        
        return;
    }

private:
    int sum = 0;
};
```


