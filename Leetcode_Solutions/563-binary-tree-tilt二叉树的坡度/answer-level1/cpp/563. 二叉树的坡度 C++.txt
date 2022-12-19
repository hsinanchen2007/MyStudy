### 解题思路
递归

### 代码

```cpp

class Solution {
public:

    //1、
    struct ReturnData
    {
        int sum; //树值的和
        int tilt; //坡度

        ReturnData(int s, int t) : sum(s), tilt(t) {}
    };

    ReturnData find_tilt(TreeNode* node)
    {
        if (!node)
        {
            return ReturnData(0, 0);
        }

        ReturnData left_data = find_tilt(node->left); //左子树值的和 与 坡度
        ReturnData right_data = find_tilt(node->right);//右子树值的和 与 坡度

        int tilt = left_data.tilt + right_data.tilt + abs(left_data.sum - right_data.sum);
        int sum = left_data.sum + right_data.sum + node->val;

        return ReturnData(sum, tilt);
    }

    int findTilt(TreeNode* root) {

        if (!root)
        {
            return 0;
        }

        ReturnData left_data = find_tilt(root->left); //左子树值的和 与 坡度
        ReturnData right_data = find_tilt(root->right);//右子树值的和 与 坡度

        return left_data.tilt + right_data.tilt + abs(left_data.sum - right_data.sum);
    }


    //2、简化
    //返回当前节点这棵树值的和  tilt为当前节点的坡度
    int find_tilt(TreeNode* node, int& tilt)
    {
        if (!node)
        {
            return 0;
        }

        int left_sum = find_tilt(node->left, tilt);
        int right_sum = find_tilt(node->right, tilt);

        tilt += abs(left_sum - right_sum);
    
        return left_sum + right_sum + node->val;
    }


    int findTilt(TreeNode* root) {

        if (!root)
        {
            return 0;
        }

        int tilt = 0;
        find_tilt(root, tilt);

        return tilt;
    }
};
```