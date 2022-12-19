```
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> nodeQueue;//利用FIFO队列层序遍历
        nodeQueue.push(root);
        queue<int> indexQueue;//利用同步FIFO队列标记index
        indexQueue.push(0);
        map<int, vector<int> > dict;//利用map存遍历数据
        while(!nodeQueue.empty())
        {
            //弹出node+遍历node+入队列node左右节点
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            int index = indexQueue.front();
            indexQueue.pop();
            dict[index].push_back(node->val);
            if(node->left != nullptr)
            {
                nodeQueue.push(node->left);
                indexQueue.push(index-1);
            }
            if(node->right != nullptr)
            {
                nodeQueue.push(node->right);
                indexQueue.push(index+1);
            }
        }
        //从dict中导出矩阵ans
        for(auto col:dict)
            ans.push_back(col.second);
        return ans;
    }
};
```
