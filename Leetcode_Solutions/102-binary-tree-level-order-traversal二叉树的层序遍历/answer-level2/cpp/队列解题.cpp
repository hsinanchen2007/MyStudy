### 解题思路
没啥好说的，就一个队列，一个临时vector<int>，读出来的数据就往里放，左右孩子扔队列

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> re;
        queue<TreeNode*> p;
        int mark = 0;
        p.push(root);
        while (!p.empty()) {
            vector<int> valList;
            int count = 0;
            int size = p.size();
            while (count < size) {
                if (p.front() == NULL) {
                    p.pop();
                    count++;
                    continue;
                }
                valList.push_back(p.front()->val);
                p.push(p.front()->left);
                p.push(p.front()->right);
                p.pop();
                count++;
            }
            if (valList.size() != 0)
                re.push_back(valList);
        }   
        return re;     
    }
};
```