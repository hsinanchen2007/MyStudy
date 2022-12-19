首先想到层序遍历迭代，代码如下：
```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> tmp;
        queue<TreeNode*> node_queue;
        int length=0;
        if (root)
        {
            node_queue.push(root);
            while (!node_queue.empty())
            {
                length=node_queue.size();
                for (int i=0;i<length;i++)
                {
                    if (node_queue.front()->left)
                        node_queue.push(node_queue.front()->left);
                    if (node_queue.front()->right)
                        node_queue.push(node_queue.front()->right);
                    tmp.push_back(node_queue.front()->val);
                    node_queue.pop();
                }
                res.insert(res.begin(),tmp);
                tmp.clear();
            }
        }
        return res;
    }
};
```
上述方法运行很慢，改用递归

```
class Solution {
public:
    void DFS(TreeNode* root, int level, vector<vector<int>>& arr)
    {
        if (root==NULL)
            return;
        if (arr.size()<=level)
        {
            vector<int> tmp;
            arr.push_back(tmp);
        }
        arr[level].push_back(root->val);//注意这里不能取最后一个vector添加元素，因为归的时候最后一个vector已经不是这一层的vector了
        DFS(root->left,level+1,arr);
        DFS(root->right,level+1,arr);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        DFS(root,0,res);
        reverse(res.begin(),res.end());
        return res;
    }
};
```


