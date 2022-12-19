### 解题思路
题目要求判断一棵树是否是平衡树，那么只要知道一棵树的左树高度，右树高度，两者之差，是否符合定义即可。
第一种写法没有将root包括进去
第二种写法改进了，这里认为，要获取高度，需要一个返回int的函数，但是在判断每个节点的树时又需要一个flag进行判断。
后序遍历过程为佳，高度是自底向上求得的。flag参数判断是否符合定义

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
      // 2020/1/23  判断是否是一颗高度平衡二叉树
      if(!root) return true;
      bool flag=true;
     
      int h1=getHeight(root->left,flag);
      int h2=getHeight(root->right,flag);
      if(!flag) return false;
      if(fabs(h1-h2)<=1) return true;
      else return false;
      
    }
    int getHeight(TreeNode* root,bool& flag){
        if(!root) return 0;
        else{
            int h1=getHeight(root->left,flag);
            int h2=getHeight(root->right,flag);
            if(fabs(h1-h2)>=2) flag=false;
            return max(h1,h2)+1;
        } 

    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
      // 2020/1/23  判断是否是一颗高度平衡二叉树
      if(!root) return true;
      bool flag=true;
     
      getHeight(root,flag);
      if(!flag) return false;
      return true;
      
    }
    int getHeight(TreeNode* root,bool& flag){
        if(!root) return 0;
        else{
            int h1=getHeight(root->left,flag);
            int h2=getHeight(root->right,flag);
            if(fabs(h1-h2)>=2) flag=false;
            return max(h1,h2)+1;
        } 

    }
};
```
