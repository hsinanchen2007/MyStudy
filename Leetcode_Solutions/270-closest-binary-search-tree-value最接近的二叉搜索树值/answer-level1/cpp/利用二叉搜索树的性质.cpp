用left表示较小值，用right表示较大值：
```cpp
class Solution 
{
public:
    int closestValue(TreeNode* root, double target)
    {
        int left = -1;
        int right = -1;
        auto head = root;
        while (head != nullptr)
        {
            if (target > head->val)
            {
                left = head->val;
                head = head->right;
            }
            else
            {
                right = head->val;
                head = head->left;
            }
        }

        if (left == -1)
        {
            return right;
        }
        else if (right == -1)
        {
            return left;
        }
        if (target - left < right - target)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};
```
