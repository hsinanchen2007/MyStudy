![image.png](https://pic.leetcode-cn.com/9e88a23a9be2b517d93af7bef3842681246b78e35381e4045318e47778d58737-image.png)

### 解题思路
观察可以发现此题结果和层次遍历的唯一区别是偶数行顺序相反
所以我们直接在偶数行调用reverse即可，遍历reverse的时间复杂度O(n)

```cpp
    for (int i=0;i<res.size();i++){
        if (i%2==1){
            reverse(res[i].begin(),res[i].end());
        }
    }
```

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        TreeNode* endNode = root; //指向每一层最后一个结点
        vector<int> tmpv;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            tmpv.push_back(cur->val);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
            if (cur == endNode){
                endNode = q.back();
                res.push_back(tmpv);
                tmpv.clear();
            }
        }
        // int i = 0;
        // for (auto v:res){
        //     if (i%2==1){
        //         cout << "reverse!v[0]=" << v[0] << endl;
        //         reverse(v.begin(), v.end());
        //     }
        //     i++;
        // }
        for (int i=0;i<res.size();i++){
            if (i%2==1){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};
```