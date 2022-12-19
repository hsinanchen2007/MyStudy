### 解题思路
可以用reverse直接反转，也可以用中间容器逆向输出。
两种方式执行用时和内存消耗相差无几。。。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //vector<vector<int>> result;
        vector<vector<int>> temp;
        if(!root)
            //return result;
            return temp;
        
        queue< pair<TreeNode*, int> > queue_Tree;
        queue_Tree.push(make_pair(root, 0));

        while(!queue_Tree.empty()){
            TreeNode* node = queue_Tree.front().first;
            int level = queue_Tree.front().second;
            queue_Tree.pop();

            if(level == temp.size()){
                temp.push_back(vector<int>());
            }
            temp[level].push_back(node->val);

            if(node->left)
                queue_Tree.push(make_pair(node->left, level+1));
            if(node->right)
                queue_Tree.push(make_pair(node->right, level+1));
        }

        // for(auto iter = temp.rbegin(); iter != temp.rend(); iter++){
        //     result.push_back(*iter);
        // }
        reverse(temp.begin(),temp.end());
        return temp;
        //return result;
    }
};
```