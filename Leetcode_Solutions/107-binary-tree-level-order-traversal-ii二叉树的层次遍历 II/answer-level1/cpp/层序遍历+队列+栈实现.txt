```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        stack<vector<int>> temp;
        int level = 0;
        vector<int> item;
        queue<pair<int,TreeNode *>> que;
        que.push(make_pair(level,root));
        while(!que.empty()){
            int last_level = level;    //当前的层数
            level++;                   //下一层的层数
            item.clear();
            while(que.front().first==last_level){
                TreeNode *node = que.front().second;
                que.pop();
                if(!node) continue;    //这一句能提高性能
                if(node) item.emplace_back(node->val);
                if(node && node->left) que.push(make_pair(level,node->left));
                if(node && node->right) que.push(make_pair(level,node->right));
            }
            temp.push(item);
        }
        while(!temp.empty()){
            result.emplace_back(temp.top());
            temp.pop();
        }
        return result;
    }
};

```
既然是层序遍历，而且是从下往上输出，很快就能想到用栈。101那道题做不对，就是因为当时没有用last_level这个策略。要想一层一层的操作，那么肯定就需要make_pair (level,root) 来记录层数。在添加当前层的左右孩子进队列的时候，层数需要加一。不过可能有的有左孩子有的有右孩子有的都有有的都没有，如果层数在make_pair (level++,node->left))添加的话，会出现混乱，所以得在这个while外面添加。