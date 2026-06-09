```cpp
/* 不使用哈希表，而是使用数组和队列。 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<pair<int, long long>> book;  // <level, <cnt, sum>>
        queue<pair<int, TreeNode*>> q;    // <level, Node*>
        
        if(root) 
            q.push(make_pair(0, root));
        
        while(!q.empty()) {
            pair<int, TreeNode*> f = q.front();
            int cur_level = f.first;
            TreeNode *cur_node = f.second;
            
            if(book.size() <= cur_level)
                book.push_back(make_pair(0, 0));
            book[cur_level].first += 1;
            book[cur_level].second += cur_node->val;
            
            q.pop();
            if(cur_node->left)
                q.push(make_pair(cur_level + 1, cur_node->left));
            if(cur_node->right)
                q.push(make_pair(cur_level + 1, cur_node->right));
        }
        
        for(pair<int, long long> pr : book)
            ans.push_back(pr.second / static_cast<double>(pr.first));
        return ans;
    }
};
```
