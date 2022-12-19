# 整体思路：
将所有节点按从左到右的顺序放进一个队列，然后处理队列，
这里最主要的矛盾是每次需要处理多少个？
用一个变量记录当前队列中的节点个数，即为一层的节点数。
用level记录当前层数，可解答104题
```

class Solution {
public:
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level = 0;
        vector<vector<int>> tempV;
        queue<TreeNode*> tempQ;
        if(!root) return tempV;
        tempQ.push(root);

        while(!tempQ.empty()) {
            int curNum = tempQ.size();
            vector<int> vecLevel;
            //proc all node of the same level
            for(;curNum > 0; curNum--) {
                TreeNode *q = tempQ.front();
                tempQ.pop();
                vecLevel.insert(vecLevel.end(), q->val);
                if(q && q->left) tempQ.push(q->left);
                if(q && q->right) tempQ.push(q->right);
            }
            tempV.insert(tempV.begin(), vecLevel);
            //level ++; 
        }
        return tempV;
    }
};
```
