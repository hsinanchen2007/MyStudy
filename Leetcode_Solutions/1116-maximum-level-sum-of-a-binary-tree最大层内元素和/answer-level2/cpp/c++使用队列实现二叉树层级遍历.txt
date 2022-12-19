![image.png](https://pic.leetcode-cn.com/1fa546d26ba3c8f6846c50444d2b585429b70b75704afddf6672cf540075eb6f-image.png)
```
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> eachLevel;

        if (root != NULL) {
            eachLevel.push(root);
        }

        int level = 1;
        int maxLvSum = 0;

        while (!eachLevel.empty()) {
            int curSize = eachLevel.size();
            int curLvSum = 0;

            for (int loop = 0; loop < curSize; ++loop) {
                TreeNode* curLevel = eachLevel.front();
                eachLevel.pop();

                curLvSum += curLevel->val;

                if (curLevel->left != NULL) {
                    eachLevel.push(curLevel->left);
                }

                if (curLevel->right != NULL) {
                    eachLevel.push(curLevel->right);
                }
            }

            if (curLvSum > maxLvSum) {
                maxLvSum = curLvSum;
                result = level;
            }

            level++;
        }

        return result;
    }
};
```
