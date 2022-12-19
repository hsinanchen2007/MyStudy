思路： 感觉示例就是在给提示。
       每个子问题是将父节点和左右子节点的硬币进行分配。这个过程可以简化为，将子节点的多余硬币移动至父节点，或是将父节点的多余硬币移动至子节点。
       如示例3：  ![image.png](https://pic.leetcode-cn.com/9d1bce2995410f23fed0d83a4b7edb1e1c4d2ab5a1727fa9213832209442cfd9-image.png)
       左节点缺1个硬币，从父节点拿1个硬币。右节点多1个硬币，给父节点1个硬币。所以是2。
       用左右子树代替左右节点的时候，移动的硬币就不止1个了。通过递归判断父节点的左右子树硬币多余或缺少的情况。统一移动到父节点。
       对每个父节点都进行子节点硬币的情况判断，累加需要移动的步数。
```C++ []
class Solution {
public:
    int ans = 0;
    
    int distributeCoins(TreeNode* root) {
        countNeed(root);
        return ans;
    }
    
    int countNeed(TreeNode *root){
        if(!root) return 0;
        int need = 1-root->val;
        int left = countNeed(root->left);
        int right = countNeed(root->right);
        ans += abs(left)+abs(right);
        return left+right+need;
    }
};
```
