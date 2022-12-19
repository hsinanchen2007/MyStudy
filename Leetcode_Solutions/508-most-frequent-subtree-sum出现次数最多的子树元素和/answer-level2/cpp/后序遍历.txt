### 解题思路
后序遍历见注释

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
    set<int> res_pre;  //先用set存数防止重复
    int max_count=-1;
    map<int,int> m;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        res.assign(res_pre.begin(), res_pre.end()); //set中的值放到 vector中再返回，assign的方式记下来
        return res;
    }
    int dfs(TreeNode* root){  //后序遍历
        if(root==NULL) return 0;

        int l=dfs(root->left);
        int r=dfs(root->right);

        int sum=r+l+root->val;   //此节点子树和
        if(m.count(sum)) m[sum]++;  //在map中存下来出现次数
        else m[sum]=1;
        if(max_count<m[sum]){    //最大次数变化，清空set，重新存入
            max_count=m[sum];
            res_pre.clear();
            res_pre.insert(sum);
        }else if(max_count==m[sum]){  //达到目前最大次数，存入
            res_pre.insert(sum);
        }

        return sum;
    }
};
```