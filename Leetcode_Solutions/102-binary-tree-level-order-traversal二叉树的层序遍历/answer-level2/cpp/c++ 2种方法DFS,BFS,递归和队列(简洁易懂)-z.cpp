做了这道题的童鞋可以顺带做一下103，一样的思路，细节不同
[103.二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/c-2chong-fang-fa-dfsbfsdi-gui-he-dui-lie-jian-ji-y/)
### DFS

```cpp
class Solution {
public:
    vector<vector<int>> res;   
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        addVector(root,0);      //调用递归函数
        return res;
    }
  
    void addVector(TreeNode* root,int level)
    {
        if(root == NULL)    return;
        if(res.size()==level)       res.resize(level+1);    //level表示层数，也对应二维数组的第一层索引，
        res[level].push_back(root->val);
        addVector(root->left,level+1);
        addVector(root->right,level+1);
    }
};
```

### BFS

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == NULL)   return {};  
        queue<TreeNode*> q;     
        q.push(root);  

        while (!q.empty()) 
        {  
            vector<int>level;                //存放每一层的元素值
            int count=q.size();             //队列大小表示当前层数的元素个数
            while(count--)                  //count--逐个对该层元素进行处理
            {
            TreeNode *t=q.front();             q.pop();     
            level.push_back(t->val);
            if(t->left)     q.push(t->left);
            if(t->right)    q.push(t->right);
            }

            res.push_back(level);           //将当层元素的vector加入res中
        }
        return res;
        }
};
```
