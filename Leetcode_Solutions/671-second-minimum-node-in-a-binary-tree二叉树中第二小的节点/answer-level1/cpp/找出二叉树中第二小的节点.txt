### 解题思路
递归

### 代码

```cpp

class Solution {
public:
    //找到第二小的值
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL)return -1;
        //一个叶子节点也没有第二最小值
        if(root->left==NULL && root->right==NULL)return -1;
        int left=root->left->val;
        int right=root->right->val;
        //如果子节点正好相等，继续往下找第二小的值，找到了就替换
        if(root->val==root->left->val) left=findSecondMinimumValue(root->left);
        if(root->val==root->right->val) right=findSecondMinimumValue(root->right);
        //两边都找到，左右子树当前值进行比较，返回较小的
        if(left!=-1&&right!=-1)return left<right?left:right;
        //右树没找到，返回左边找到的
        if(left!=-1)return left;
        //其余情况（左树没找到），返回右边的
        return right;
    }
};
```