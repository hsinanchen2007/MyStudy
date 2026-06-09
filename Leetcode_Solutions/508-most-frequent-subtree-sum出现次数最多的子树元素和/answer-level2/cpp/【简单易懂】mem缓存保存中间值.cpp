### 解题思路
1.DFS求解每个节点对应的子和；
2、用map保存起来；
3、排序出最多的那个
4、返回；

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, int> map1;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int s = Dfs(root);
        map<int, int> map2;
        for (pair<TreeNode*, int> pair1 : map1) {
            if (map2.find(pair1.second) != map2.end()) {
                map2[pair1.second] = map2[pair1.second] + 1;
            } else {
                map2.insert(make_pair(pair1.second, 1));
            }
        }
        int maxCount = 0;
        for (pair<int, int> pair2 : map2) {
            maxCount = max(maxCount, pair2.second);
        }
        vector<int> result;
        for (pair<int, int> pair2 : map2) {
            if (maxCount == pair2.second) {
                result.push_back(pair2.first);
            }
        }
        return result;
    }
    
    int Dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (map1.find(root) != map1.end()) {
            return map1[root];
        }
        int result = root->val + Dfs(root->left) + Dfs(root->right);
        map1[root] = result;
        return result;
    }
};
```