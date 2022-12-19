解题思路：
    1.前序遍历此二叉树，并设置变量value记录当前路径下从根节点到当前节点的和；
    2.若到达叶子结点（即节点的左子节点和右子节点均为空），且value值与目标和相等，则证明该路径之和等于目标值，返回true;
    3.若该叶子节点不是所求路径或继续遍历，则记得从value值中减去当前节点的值

代码如下（可能可以进一步优化进行**剪枝操作**）：
```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int value=0;
        bool result=false;
        preOrder(root,sum,value,result);
        return result;
    }

private:
    void preOrder(TreeNode* node,int targetSum,int &value,bool &get_result){
        if(!node){
            return;
        }
        value += node->val;
        //进一步优化，可进行剪枝操作
        //当当前节点之和大于目标和，可直接放弃该段
        //考虑到正负情况，不能简单进行剪枝
        // if(value > targetSum){
        //     value -= node->val;
        //     return;
        // }

        //如果到达叶子节点，且和等于目标值，则返回true
        if((node->left==NULL) && (node->right==NULL) && (value==targetSum)){
            get_result=true;
        }
        preOrder(node->left,targetSum,value,get_result);
        preOrder(node->right,targetSum,value,get_result);
        value -=node->val;
        return;
    }
};
```
    