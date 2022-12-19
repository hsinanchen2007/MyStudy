### 解题思路
思路：保存最大值和最小值，每逢左子树更新最小值，右子树更新最大值，有问题就false，没毛病就继续
缺点：递归嘛，做好内存惨不忍睹的准备。。。

### 代码

class Solution {
public:
    bool isValidBST_core(TreeNode*  & ptr, long lowerbound, long upperbound) {
        if (ptr == NULL) return true;
        //左子树元素要比最小的值还小，右子树元素要比最大的值还大。
        if (ptr->val >= lowerbound || ptr->val <= upperbound) return false;
        long _lowerbound = ptr->val < lowerbound ? ptr->val : lowerbound;
        long _upperbound = ptr->val > upperbound ? ptr->val : upperbound;
        TreeNode* leftptr = ptr->left;
        TreeNode* rightptr = ptr->right;
        bool ans1 = isValidBST_core(leftptr, _lowerbound, upperbound);
        bool ans2 = isValidBST_core(rightptr, lowerbound, _upperbound);
        return ans1 && ans2;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST_core(root, long(INT_MAX)+1, long(INT_MIN)-1);
    }
};
```