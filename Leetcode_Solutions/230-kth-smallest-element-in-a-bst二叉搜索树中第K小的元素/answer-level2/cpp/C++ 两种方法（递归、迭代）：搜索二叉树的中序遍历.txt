### 解题思路
此处撰写解题思路

### 代码

```cpp
方法1：递归
class Solution {
public:
    int n=0;
    int res;
    int kthSmallest(TreeNode* root, int k) {
        //递归
        dfs(root,k);
        return res;
    }

    void  dfs(TreeNode* root,int k){
          if(!root)return ;
          dfs(root->left,k);
          n++;
          if(n==k) res=root->val;
          dfs(root->right,k);
    }
};

```


方法2：迭代
```
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        //迭代
        stack<TreeNode*>sk;
         int res;
         int n=0;
         TreeNode* cur=root;
         while(!sk.empty()||cur){
            while(cur){
                sk.push(cur);
                cur=cur->left;
            }
            cur=sk.top();
            sk.pop();
            n++;
            if(n==k)return cur->val;
            cur=cur->right;
         }
         return 0;
    }
};
```

