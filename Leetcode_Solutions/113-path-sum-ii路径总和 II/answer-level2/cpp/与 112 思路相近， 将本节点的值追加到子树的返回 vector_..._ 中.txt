### 解题思路
递归结束条件是到达叶子节点， 并且此时 sum 和 节点值相等， 说明此叶子路径节点有解
递归函数返回值为子树所有满足和为 sum 的路径
递归过程是不断的将子本节点的值加入到子树返回的所有解当中， 因为无论返回多少个解， 都经过了本节点， 所以只要循环返回值， 并且将本节点的值追加到没资格 vector 中即可
并且左右子树的解都要追加进来

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
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        vector<vector<int>> ret = __pathSum(root, sum);
        for(int i = 0; i < ret.size(); i++){ // 反转结果， 反转前vector 中顺序是从叶子节点到根节点的
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
    };

    vector<vector<int>> __pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }
        if(root -> left == NULL && root -> right == NULL && sum == root -> val){ // 说明此叶子节点的路径有解
            vector<int> inRet;
            inRet.push_back(root -> val);
            ret.push_back(inRet);
            return ret;
        }
        vector<vector<int>> leftS = __pathSum(root -> left, sum - root -> val); // 左子树存在解， 将解放入  ret 中
        if(leftS.size() != NULL){ // 说明存在
            for(int i = 0; i < leftS.size(); i++){
                leftS[i].push_back(root -> val);
                ret.push_back(leftS[i]);
            }
        }
        vector<vector<int>> rightS = __pathSum(root -> right, sum - root -> val);// 右子树存在解， 将解放入  ret 中
        if(rightS.size() != NULL){ // 说明存在
            for(int i = 0; i < rightS.size(); i++){
                rightS[i].push_back(root -> val);
                ret.push_back(rightS[i]);
            }
        }
        return ret;
    }
};
```