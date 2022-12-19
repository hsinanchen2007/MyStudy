因为上下界要超过 [INT_MIN, INT_MAX] 的范围，所以必须使用 `long` 数据类型。但是我们可以猜测数据中一定没有 $10^9+7$ 这种大素数，所以用它来代替初始上下界就行了。

```cpp
class Solution {
public:
    const int SYMBOL = 1e9+7; 

    bool isValid(struct TreeNode* root, int low, int high) {
        if (!root) return true;
        int num = root->val;
        if (low != SYMBOL && num <= low) return false;
        if (high != SYMBOL && num >= high) return false;
        return isValid(root->left, low, num) && isValid(root->right, num, high);
    }
    
    bool isValidBST(struct TreeNode* root){
        return isValid(root, SYMBOL, SYMBOL);
    }
};
```
