### 解题思路

- 中序遍历：由二叉搜索树的性质可知，中序遍历的结果是一个有序数组。也就将问题转换为求一个有序数组中的众数。
- 更新规则：判断当前的数字是否和上一个数字相同。
  - 相同，则将当前数字的次数加一；
  - 不同，则将上一个数字的次数同最大次数进行比较，更新结果。

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        int curTimes = 0; // 当前数字的次数
        int nnum = 0; // 当前处理的数字
        int maxTimes = 0; // res中的数字次数，即树中目前频率最大的数字次数
        // 中序遍历
        TreeNode *pnode, *tmp;
        pnode = root;
        while(pnode){
            if(pnode->left){
                tmp = pnode->left;
                while(tmp->right != nullptr && tmp->right != pnode){
                    tmp = tmp->right;
                }
                if(tmp->right == nullptr){
                    tmp->right = pnode;
                    pnode = pnode->left;
                    continue;
                }
                else{
                    tmp->right = nullptr;
                }
            }
            /* 处理一个节点 */
            if(pnode->val == nnum){
                curTimes++;
            }
            else{
                if(curTimes > 0 && curTimes >= maxTimes){
                    if(curTimes > maxTimes){
                        res.clear();
                        maxTimes = curTimes;
                    }
                    res.push_back(nnum);
                }
                curTimes = 1;
                nnum = pnode->val;
            }
            pnode = pnode->right;
        }
        if(curTimes > 0 && curTimes >= maxTimes){
            if(curTimes > maxTimes){
                res.clear();
                maxTimes = curTimes;
            }
            res.push_back(nnum);
        }
        return res;
    }
};
```