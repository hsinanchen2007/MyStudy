这道题有递归和非递归两种方法，首先来看递归方法。

递归方法是分别遍历一个节点的右节点和左节点，因为是从右边看过来，所以我们需要首先遍历右节点。这里有个疑问，当遍历左节点时候，怎么判定它右边没有其他节点了呢？这里我们用到一个变量level，对于同一层的节点，如果res数组的大小已经等于level了，说明右边已经有节点存入数组了，该节点就不用再保存。一直递归下去就可以得到结果。
代码一：

```C++ []
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;        
    }
    void helper(TreeNode* root,int level,vector<int>& res){
        if(!root) return;
        if(res.size()==level) res.push_back(root->val);
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);
    }
};
```

下面看一下非递归的方法。这道题要求我们打印出二叉树每一行最右边的一个数字，实际上是求二叉树层序遍历的一种变形，我们只需要保存每一层最右边的数字即可，还是需要用到数据结构队列queue，遍历每层的节点时，把下一层的节点都存入到queue中，每当开始新一层节点的遍历之前，先把新一层最后一个节点值存到结果中，代码如下：

```C++ []
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.back()->val);
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* t=q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }           
        }
        return res;
    }
};
```
