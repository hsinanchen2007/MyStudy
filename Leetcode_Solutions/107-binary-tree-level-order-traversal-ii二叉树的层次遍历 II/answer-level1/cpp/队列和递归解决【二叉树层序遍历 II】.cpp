因为最终的结果需要最后一层的结果在最前面，所以自然想到递归，避免了在vector中进行reverse操作。
在递归中，不急于把当前层次的遍历结果放入结果集res中，而是先检查队列queue是否为空，不空说明还有下一层节点需要遍历。
当直到队列为空，各层的结果已经在调用栈中保存了，再加入res即可。
以空间换时间，所以耗费空间有些多。
```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        levelOrderRecur(que, res);
        return res;
    }

    void levelOrderRecur(queue<TreeNode*>& que, vector<vector<int>>& res){
        vector<int> temp_level; // 当前层次遍历结果
        int size = que.size();
        for(int i = 0; i < size; i++){
            TreeNode* tnode = que.front(); que.pop();
            temp_level.push_back(tnode->val);
            if(tnode->left)
                que.push(tnode->left);
            if(tnode->right)
                que.push(tnode->right);
        }
        if(que.size() > 0){
            levelOrderRecur(que, res);
        }
        res.push_back(temp_level);
    }
};
```
