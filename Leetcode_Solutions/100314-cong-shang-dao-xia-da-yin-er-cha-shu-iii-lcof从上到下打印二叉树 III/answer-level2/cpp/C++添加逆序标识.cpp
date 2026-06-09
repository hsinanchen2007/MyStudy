### 解题思路

该题的程序逻辑与上一题的区别 就在于在偶数层的时候需要逆序输出
所以可以添加一个 层数标识和反转数组函数来解决

### 代码

```cpp

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int> > res;
        vector<int> v;
        
        TreeNode* first = root;  //用于判断是否到头
        int count = 1;  //是否反转顺序判断
        queue<TreeNode*> q;
        q.push(root);

        //逆层序遍历
        while(!q.empty()){
            TreeNode* temp = q.front();
            v.push_back(temp->val);
            q.pop();

            if (temp->right != NULL) q.push(temp->right);
            if (temp->left != NULL) q.push(temp->left);

            if(temp == first ){
                first = q.back();
                if(count%2 != 0)  reverse(v);
                res.push_back(v);
                v.clear();
                count++;
            }
        }
        return res;
    }
    void reverse(vector<int>&v){
    for(int i = 0;i < v.size()/2; ++i){
        swap(v[i],v[v.size()-1-i]);
        }
    }
};
```