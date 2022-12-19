### DFS
[102.二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/c-dui-lie-yi-dong-z-by-zrita/)
ps:这道题其实就是102.二叉树的层次遍历的翻版，多了一个条件if(level %2==0),层数level从0开始表示二叉树的第一行，如果为偶数行则顺序加入，如果为奇数行则将数字每次插入到最前面

```cpp
class Solution {
public:
    vector<vector<int>> res;   
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        addVector(root,0);      //调用递归函数
        return res;
    }
  
    void addVector(TreeNode* root,int level)
    {
        if(root == NULL)    return;
        if(res.size()==level)       res.resize(level+1);    //level表示层数，也对应二维数组的第一层索引，
        if(level %2==0)                                     
            res[level].push_back(root->val);                //如果为偶数行则顺序加入，如果为奇数行则将数字每次插入到最前面
        else
            res[level].insert(res[level].begin(),root->val);

        addVector(root->left,level+1);
        addVector(root->right,level+1);          
    }
};
```

### BFS

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (root == NULL)   return {};  
        queue<TreeNode*> q;     
        q.push(root);  

        int level=0;
        while (!q.empty()) 
        {  
            vector<int>temp;                //存放每一层的元素值
            int count=q.size();             //队列大小表示当前层数的元素个数
            while(count--)                  //count--逐个对该层元素进行处理
            {
            TreeNode *t=q.front();             q.pop();    
            if(level%2 ==0) 
            temp.push_back(t->val);
            else
            temp.insert(temp.begin(),t->val);
            if(t->left)     q.push(t->left);
            if(t->right)    q.push(t->right);
            }

            level++;
            res.push_back(temp);           //将当层元素的vector加入res中
        }
        return res;
        }
};


```
