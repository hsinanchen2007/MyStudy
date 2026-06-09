两个阶段：
1. 遍历二叉树，为每个和统计出现次数，记录在map中
2. 遍历map，将最大的值存到vector中
  
代码如下：
```
class Solution {
public:
    map<int, int> mmap;

    vector<int> findFrequentTreeSum(TreeNode *root) {
        getSum(root);
        vector<int> res;
        int maxCount = -1;
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            if (it->second > maxCount) {
                res.clear();
                res.push_back(it->first);
                maxCount = it->second;
            } else if (it->second == maxCount) {
                res.push_back(it->first);
            }
        }
        return res;
    }

    int getSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int sum = root->val;
        if (root->left) {
            sum += getSum(root->left);
        }
        if (root->right) {
            sum += getSum(root->right);
        }
        mmap[sum]++;
        return sum;
    }
};
```