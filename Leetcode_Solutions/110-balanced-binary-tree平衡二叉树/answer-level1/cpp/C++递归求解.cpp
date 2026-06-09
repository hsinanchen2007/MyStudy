### 解题思路
递归求解超级简单，一看就懂

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
    int leftnum,rightnum;
    bool flag=true;
    void dfs_sum(TreeNode* root,int &sum){//求节点有多深
        if(!root) return ;
        int temp;
        sum+=1;
        temp=sum;
        dfs_sum(root->left,sum);//分别求左右节点
        int m=sum;
        sum=temp;
        dfs_sum(root->right,sum);//分别求左右节点
        int n=sum;
        sum=max(m,n);//返回两个节点中较大的那个sum值
    }
    int getnum(TreeNode* root){
        int sum=0;
        dfs_sum(root,sum);
        return sum;//返回长度
    }
    void checkflage(TreeNode* root){
        if(!root) return ;
        leftnum = getnum(root->left);
        rightnum = getnum(root->right);
        if(abs(leftnum-rightnum)>1)
        {   
            flag=false;
        }
        checkflage(root->left);
        checkflage(root->right);

    }
    bool isBalanced(TreeNode* root) {
        checkflage(root); 
        if(flag==true)
            return true;
        else
            return false;
    }
};
```