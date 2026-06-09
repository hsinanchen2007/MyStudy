### 解题思路
该题与二叉树有关，需要用到递归，解题思路如下:
* 入参检查
* 求左右子树的深度
* 判定节点是否为叶子节点
* 并求出左右子树的最小值

### 代码

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        //入参检查
        if (root == nullptr) 
        {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (root->left == nullptr || root->right == nullptr)
        {
            return left == 0 ? right+1 : left +1;
        }
        else
        {
            return min(left, right) + 1;
        }  
    }
};
```